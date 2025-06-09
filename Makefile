kernel: entry.s main.c helper.c helper.h linker.ld
	gcc -O3 -ffreestanding -o kernel entry.s main.c helper.c -nostdlib -m32 -g -T linker.ld -no-pie -mgeneral-regs-only -fno-stack-protector

run: kernel
	qemu-system-i386 -kernel ./kernel -nographic -s -no-reboot -d int

clean:
	rm -rf kernel
