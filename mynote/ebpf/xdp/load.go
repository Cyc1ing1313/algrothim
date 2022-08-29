package main

import (
	"fmt"
	"net"
	"os/exec"
	"time"

	"github.com/cilium/ebpf"
	"github.com/cilium/ebpf/link"
	"github.com/cilium/ebpf/rlimit"
)

func compile() {
	cmd := exec.Command("/bin/bash", "-c", "sh build.sh xdp")
	buff, err := cmd.Output()
	if err != nil {
		panic(err)
	}
	fmt.Printf("%s\n\n", buff)
}

func main() {
	compile()
	err := rlimit.RemoveMemlock()
	if err != nil {
		panic(err)
	}
	spec, err := ebpf.LoadCollectionSpec("xdp.o")
	if err != nil {
		panic(err)
	}
	var obj struct {
		XCProg *ebpf.Program `ebpf:"myprog"`
		XCMap  *ebpf.Map     `ebpf:"packet_cnt"`
	}
	if err = spec.LoadAndAssign(&obj, nil); err != nil {
		panic(err)
	}
	defer obj.XCMap.Close()
	defer obj.XCProg.Close()

	dev, err := net.InterfaceByName("ens33")
	if err != nil {
		panic(err)
	}
	l, err := link.AttachXDP(link.XDPOptions{
		Program:   obj.XCProg,
		Interface: dev.Index,
	})
	if err != nil {
		panic(err)
	}
	defer l.Close()
	var key uint32
	var value uint32
	for range time.Tick(time.Second) {
        itr := obj.XCMap.Iterate()
		for itr.Next(&key, &value) {
			fmt.Printf("protocal %d count %d\n", key, value)
		}
        fmt.Println("end")
		if err := itr.Err(); err != nil {
			panic(err)
		}
	}
}
