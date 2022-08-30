echo $1
as --32 $1.s -o $1.o  && ld -melf_i386 $1.o -o $1