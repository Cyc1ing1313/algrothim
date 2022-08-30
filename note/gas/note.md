# gas汇编笔记
## 寄存器的用处
有两种寄存器，通用寄存器和专用寄存器

通用：

1. %eax 系统调用的调用号入参
2. %ebx 返回参数
3. %ecx
4. %edx
5. %edi
6. %esi

专用：

1. %ebp 获取函数参数和本地变量的寄存器，栈底指针
2. %esp 栈顶寄存器
3. %eip 程序计数器
4. %eflags

## 符号指令
1. int 表示中断，例如int $0x80
2. .section .data 标记数据段
3. .section .text 标记代码段
4. .globl _start 标记入口
5. .section .bss 不需要初始化的数据段 
6. .lcomm my_buffer,500声明500byte的数据段，搭配.section .bss使用
7. .equ LINUX_SYSCALL,0x80 类似宏，用字符串LINUX_SYSCALL代替0x80
## 函数
### 内存布局
   <img src="https://lishiwen4.github.io/images/linux/memory-location1.png">

### 栈
   栈顶指针%esp,pushl,esp+4,popl,esp-4
### 约定
1. 函数参数被逆序push进函数栈中
2. call指令把函数的返回地址压入栈中，然后修改%eip指向函数的起始地址
   
    #### 标准步骤
    1. 保存%ebp的值，pushl %ebp 
    2. movl %esp,%ebp 保存栈顶指针


    ```
        Parameter #N     <--- 4*N+4(%ebp) 
        ...
        Parameter 2      <--- 12(%ebp)
        Parameter 1      <--- 8(%ebp)
        Return Address   <--- 4(%ebp)
        Old %ebp         <--- (%ebp)
        Local Variable 1 <--- -4(%ebp)
        Local Variable 2 <--- -8(%ebp) and (%esp)   
    ```
    3. 退出函数

    ```
    movl %ebp, %esp
    popl %ebp
    ret
    ```
## 几种寻址模式
通用公式
```
ADDRESS_OR_OFFSET(%BASE_OR_OFFSET,%INDEX,MULTIPLIER)

FINAL ADDRESS = ADDRESS_OR_OFFSET + %BASE_OR_OFFSET + MULTIPLIER * %INDEX
```
1. 直接寻址模式
   
```
movl ADDRESS, %eax
```
ADDRESS地址的值写入eax寄存器里

2. 间接寻址模式

```
movl (%eax), %ebx
```
eax寄存器里的值当做地址，该地址指向的数据写到ebx里

3. 基地址寻址模式

```
movl  4(%eax), %ebx
```
取eax里的地址+4计算新的地址，取新地址的值写到ebx

4. 寄存器寻址模式

```
movl %eax %ebx
```
只是把寄存器eax的值写入ebx

5. 立即数模式

```
movl $12, %eax
```
将12写入eax寄存器

6. 索引寻址模式
```
movl string_start(,%ecx,1), %eax
```
string_start地址+1*%ecx算出新的地址，然后把新地址的数据写入eax寄存器
