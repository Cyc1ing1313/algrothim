#!/bin/bash
NAME=$1
sudo tc qdisc del dev $NAME ingress