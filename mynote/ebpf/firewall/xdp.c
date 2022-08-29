#include <bpf/bpf_helpers.h>
#include <linux/bpf.h>
#include <linux/if_ether.h>
#include <linux/in.h>
#include <linux/ip.h>
#include <linux/ipv6.h>
#include <linux/tcp.h>
#include <linux/udp.h>
#define KEY_SIZE 256 / 64
#define MAX_ENTRIES 1024

#define PASS 1
#define DROP 2
#define DEFAULT_ACTION XDP_PASS

char _license[] SEC("license") = "GPL";

struct match_val {
  __u64 bits[KEY_SIZE];
};

struct addr_lpm {
  struct bpf_lpm_trie_key key;
  __u32 addr;
};

struct bpf_map_def SEC("maps") proto_map = {
    .type = BPF_MAP_TYPE_HASH,
    .key_size = sizeof(__u32),
    .value_size = sizeof(struct match_val),
    .max_entries = MAX_ENTRIES,
    .map_flags = 0};

struct bpf_map_def SEC("maps") dst_port_map = {
    .type = BPF_MAP_TYPE_HASH,
    .key_size = sizeof(__u32),
    .value_size = sizeof(struct match_val),
    .max_entries = MAX_ENTRIES,
    .map_flags = 0};

struct bpf_map_def SEC("maps") src_port_map = {
    .type = BPF_MAP_TYPE_HASH,
    .key_size = sizeof(__u32),
    .value_size = sizeof(struct match_val),
    .max_entries = MAX_ENTRIES,
    .map_flags = 0};

struct bpf_map_def SEC("maps") dst_lpm_map = {
    .type = BPF_MAP_TYPE_LPM_TRIE,
    .key_size = sizeof(struct addr_lpm),
    .value_size = sizeof(struct match_val),
    .max_entries = MAX_ENTRIES,
    .map_flags = 0};

struct bpf_map_def SEC("maps") dst_hash_map = {
    .type = BPF_MAP_TYPE_HASH,
    .key_size = sizeof(__u32),
    .value_size = sizeof(struct match_val),
    .max_entries = MAX_ENTRIES,
    .map_flags = 0};

struct bpf_map_def SEC("maps") src_lpm_map = {
    .type = BPF_MAP_TYPE_LPM_TRIE,
    .key_size = sizeof(struct addr_lpm),
    .value_size = sizeof(struct match_val),
    .max_entries = MAX_ENTRIES,
    .map_flags = 0};

struct bpf_map_def SEC("maps") src_hash_map = {
    .type = BPF_MAP_TYPE_HASH,
    .key_size = sizeof(__u32),
    .value_size = sizeof(struct match_val),
    .max_entries = MAX_ENTRIES,
    .map_flags = 0};

struct bpf_map_def SEC("maps") action_map = {.type = BPF_MAP_TYPE_ARRAY,
                                             .value_size = sizeof(__u32),
                                             .key_size = sizeof(__u32),
                                             .max_entries = MAX_ENTRIES,
                                             .map_flags = 0};

struct match_res {
  struct match_val *src;
  struct match_val *dst;
  struct match_val *dport;
  struct match_val *sport;
  struct match_val *protocal;
};

static inline __u32 get_rule_id(__u64 bits[KEY_SIZE]) {
  int idx = 0;
  int i = 0;
  __u64 b;
  for (idx = KEY_SIZE - 1; idx >= 0; idx--) {
    b = bits[idx];
    b = b & (-b);
    while (b) {
      b = b >> 1;
      i++;
    }
    if (i > 0) {
      return idx * 64 + i;
    }
  }
  return -1;
}

static inline int acl_miss() { return -1; }

static inline int match_ip(struct iphdr *iphdr, struct match_res *res) {
  struct match_val *val;
  struct addr_lpm key = {.addr = iphdr->saddr,
                         .key = {
                             .prefixlen = 32,
                         }};
  if (!(val = bpf_map_lookup_elem(&src_hash_map, &iphdr->saddr))) {
    if (!(val = bpf_map_lookup_elem(&src_lpm_map, &key))) {
      return -1;
    }
  }
  res->src = val;
  key.addr = iphdr->daddr;
  if (!(val = bpf_map_lookup_elem(&dst_hash_map, &iphdr->daddr))) {
    if (!(val = bpf_map_lookup_elem(&dst_lpm_map, &key))) {
      return -1;
    }
  }
  res->dst = val;
  return 0;
}

static inline int match_port(__u8 proto, struct xdp_md *ctx, __u64 offset,
                             struct match_res *res) {
  void *data = ctx->data;
  void *data_end = ctx->data_end;
  struct match_val *val;
  if (proto == IPPROTO_UDP) {
    struct udphdr *udphdr = data + offset;
    if (udphdr + 1 > data_end) {
      return -1;
    }
    if (!(val = bpf_map_lookup_elem(&dst_port_map, &udphdr->dest))) {
      return -1;
    }
    res->dport = val;
    if (!(val = bpf_map_lookup_elem(&src_port_map, &udphdr->source))) {
      return -1;
    }
    res->sport = val;
    return 0;
  } else if (proto == IPPROTO_TCP) {
    struct tcphdr *tcphdr = data + offset;
    if (tcphdr + 1 > data_end) {
      return -1;
    }
    if (!(val = bpf_map_lookup_elem(&dst_port_map, &tcphdr->dest))) {
      return -1;
    }
    res->dport = val;
    if (!(val = bpf_map_lookup_elem(&src_port_map, &tcphdr->source))) {
      return -1;
    }
    res->sport = val;
    return 0;
  }
  return -1;
}

static inline int do_action(struct match_res *res) {
  __u64 bits[KEY_SIZE];
  int idx;
  for (idx = 0; idx < KEY_SIZE; idx++) {
    bits[idx] = res->dport->bits[idx] & res->sport->bits[idx] &
                res->protocal->bits[idx] & res->src->bits[idx] &
                res->dst->bits[idx];  
  }
  __u32 rule_id = get_rule_id(bits);
  __u32 *action = bpf_map_lookup_elem(&action_map,&rule_id);
  if (*action == PASS) {
    return XDP_PASS;
  } else if (*action == DROP) {
    return XDP_DROP;
  }
  return DEFAULT_ACTION;
}

static inline int match(struct xdp_md *ctx, __u64 offset) {
  void *data = ctx->data;
  void *data_end = ctx->data_end;
  struct iphdr *iphdr = data + offset;
  struct match_res res = {};
  struct match_val *val;
  if (iphdr + 1 > data_end) {
    return -1;
  }
  if (!(val = bpf_map_lookup_elem(&proto_map, &iphdr->protocol))) {
    goto miss;
  }
  res.protocal = val;
  if (!match_port(iphdr->protocol, ctx, offset + sizeof(*iphdr), &res)) {
    goto miss;
  }

miss:
  return acl_miss();
}

SEC("xdp")
int root(struct xdp_md *ctx) {
  void *data = ctx->data;
  void *data_end = ctx->data_end;
  struct ethhdr *ethhdr = data;
  struct iphdr *iphdr;
  if (ethhdr + 1 > data_end) {
    return XDP_PASS;
  }
  if (ethhdr->h_proto != ETH_P_IP) {
    return XDP_PASS;
  }
}