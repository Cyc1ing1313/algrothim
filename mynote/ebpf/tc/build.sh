#!/bin/bash
NAME=$1
clang -g -c -O2 -target bpf -c $NAME.c -o $NAME.o