# k8s网络
## k8s service的四种类型
1. cluster ip 
   分配给你一个内部可以访问的虚拟ip
2. node port
   你在一个node，通过不同的port来访问不同的pod
3. loadbalancer
   一般厂商提供，创建这种服务的时候，会有两个操作：
   1. kube-proxy会在主机开一个端口
   2. 厂商需要将该service ip的流量流入kube-proxy的端口
   一般有2种模式，分别是L2和L3模式：
      1. L2

   
4. external name
   使用dns映射服务到ip