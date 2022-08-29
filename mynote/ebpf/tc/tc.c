#include <bits/types.h>
#include <linux/bpf.h>
#include <linux/if_ether.h>
#include <linux/in.h>
#include <linux/ip.h>
#include <linux/pkt_cls.h>
#include <linux/tcp.h>
#include <bpf/bpf_helpers.h>
#include <string.h>
char _license[] SEC("license") = "GPL";

unsigned long long load_byte(void *skb,
                             unsigned long long off) asm("llvm.bpf.load.byte");

static inline int is_http(struct __sk_buff *skb, __u64 nh_off)
{
    void *data_end = (void *)(long)skb->data_end;
    void *data = (void *)(long)skb->data;
    struct iphdr *iphdr = data + nh_off;
    if (iphdr + 1 > data_end)
    {
        return 0;
    }
    if (iphdr->protocol != IPPROTO_TCP)
    {
        return 0;
    }
    __u32 tcp_len = 0;
    __u32 ip_len = 0;
    __u32 poffset = 0;
    __u32 plength = 0;
    __u32 ip_total_len = iphdr->tot_len;
    ip_len = iphdr->ihl << 2;
    if (ip_len < sizeof(*iphdr))
    {
        return 0;
    }
    struct tcphdr *tcphdr = data + nh_off + sizeof(*iphdr);
    if (tcphdr + 1 > data_end)
    {
        return 0;
    }
    tcp_len = tcphdr->doff << 2;
    if (tcp_len < sizeof(*tcphdr))
    {
        return 0;
    }
    poffset = ETH_HLEN + ip_len + tcp_len;     //数据的起始
    plength = ip_total_len - ip_len - tcp_len; //数据长度
    if (plength >= 7)
    {
        if (data + poffset + 8 > data_end)
        {
            return 0;
        }
        if ((*(char*)(data+poffset+0) == 'H') && (*(char*)(data+poffset+1) == 'T') && (*(char*)(data+poffset+2) == 'T') && (*(char*)(data+poffset+3) == 'P'))
        {
            return 1;
        }
    }
    return 0;
}

SEC("classifier")
int classification(struct __sk_buff *skb)
{
    void *data_end = (void *)(long)skb->data_end;
    void *data = (void *)(long)skb->data;
    struct ethhdr *eth = data;
    __u16 proto;
    __u64 nh_off;
    nh_off = sizeof(*eth);
    if (data + sizeof(*eth) > data_end)
    {
        return TC_ACT_OK;
    }
    proto = eth->h_proto;
    if (proto == __constant_htons(ETH_P_IP))
    {
        if (is_http(skb, nh_off))
        {
            bpf_printk("yes it is http");
        }
    }
    return TC_ACT_OK;
}
