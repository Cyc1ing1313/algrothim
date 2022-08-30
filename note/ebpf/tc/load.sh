#!/bin/bash
NAME=$1
BPF=$2
sudo tc qdisc del dev $NAME ingress
sudo tc qdisc add dev $NAME handle 0: ingress
sudo tc filter add dev $NAME ingress bpf obj $BPF flowid 0: