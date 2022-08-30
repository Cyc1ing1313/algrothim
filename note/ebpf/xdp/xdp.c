#include <bpf/bpf_helpers.h>
#include <linux/bpf.h>
#include <linux/types.h>
#include <linux/in.h>
#include <linux/ip.h>
#include <linux/if_ether.h>

struct bpf_map_def SEC("maps") packet_cnt = {
    .type = BPF_MAP_TYPE_HASH,
    .key_size = sizeof(__u32),
    .value_size = sizeof(__u32),
    .max_entries = 256,
    .map_flags = 0,
};

SEC("xdp")
int myprog(struct xdp_md *ctx) {
    void *data = (void *)(long)ctx->data;
    void *data_end = (void *)(long)ctx->data_end;
    struct ethhdr *ethhdr = data;
    if (ethhdr+1 > data_end) {
        return XDP_PASS;
    }
    struct iphdr *iphdr = data + sizeof(struct ethhdr);
    __u32 *cnt;
    __u32 idx;
    if( iphdr+1 > data_end) {
        return XDP_PASS;
    }
    idx = iphdr->protocol;
    cnt = bpf_map_lookup_elem(&packet_cnt,&idx);
    if(!cnt) {
        __u32 init_cnt = 1;
        bpf_map_update_elem(&packet_cnt,&idx,&init_cnt,BPF_ANY);
    } else {
        *cnt += 1;
        bpf_map_update_elem(&packet_cnt,&idx,cnt,BPF_ANY);
    }
    if (iphdr->protocol == IPPROTO_TCP) {
        return XDP_PASS;
    }
    return XDP_PASS;
}