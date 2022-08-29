.section .data
datas:
.long 1,2,3,4,5,0
.section .text
.global _start
_start:
    movl $0,%edi
    movl datas(,%edi,4),%eax
    movl %eax,%ebx
    start_loop:
        cmpl $0,%eax
        je loop_exit
        incl %edi
        movl datas(,%edi,4),%eax
        cmpl %ebx,%eax
        jle start_loop
        movl %eax,%ebx
        jmp start_loop
    loop_exit:
        movl $1,%eax
        int $0x80