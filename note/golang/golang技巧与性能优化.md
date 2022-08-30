# golang技巧与性能优化
## 对接口编程
```golang
type A struct {
    Name string
}

type B struct {
    Name string
}

type Stringable interface {
    ToString() string
}

func (a A) ToString() string {
    return a.Name
}

func (a A) PrintString() {
    fmt.Print(a.ToString())
}

func (b B) ToString() string {
    return b.Name
}

func (b B) PrintString() {
    fmt.Print(b.ToString())
}

//better
func ToString(x Stringable) string {
    return x.ToString
}

//检查A是否实现了接口Stringable
var _ Stringable = (*A)(nil)
```
## 性能优化小技巧
1. 使用strconv替代fmt.Sprintf
2. 避免[]byte转string
3. 使用stringbuilder
4. slice指定初始容量
5. msgpack代替json
6. 单例，对象池
7. map尽量使用int为key
8. 使用bufio
9. 使用结构体保存配置参数
10. 多参数配置
    ```golang
    type struct Server {
        Addr string
        Timeout int
        Port int
    }

    type Option func(*Server)

    func NewServer(options ...Option) {
        server := Server {}
        for _,opt := range options {
            opt(&server)
        }
    }

    func Timeout(timeout time.Duration) {
        return func(s *Server) {
            s.Timeout = timeout
        }
    }
    ```
11. 装饰器
    ```golang
    func Hello(s string) {
        fmt.Print("hello")
    }

    func HelloWrapper(f func (s string)) func(s string) {
        return func(s string) {
            fmt.Print("pre hello")
            f()
        }
    }

    HelloWrapper(Hello)("hello")
    ```
12. slice扩容 <= 1024 *2 >1024 *1.25