.text
.globl start
start:
	mov $stack_end, %esp
	jmp main

.bss
.balign 4096
	.skip 64*1024
stack_end:
