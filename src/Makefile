OBJ=boot.o main.o descriptor_tables.o isr.o gdt.o interrupt.o timer.o sound.o exception.o
LIB=lib/lib.a

CFLAGS=-Wall -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -Iinclude/
LDFLAGS=-melf_i386 -Tlink.ld
ASFLAGS=-felf32

all: $(OBJ) $(LIB) link

clean:
	-rm $(OBJ) kernel
	make clean -C lib/
link:
	ld $(LDFLAGS) -o kernel $(OBJ) $(LIB)
lib/lib.a:
	make lib.a -C lib/
# GNU make cannot compile assembly files with nasm explicitly
boot.o: boot.asm
	nasm $(ASFLAGS) boot.asm
gdt.o: gdt.asm gdt.h
	nasm $(ASFLAGS) gdt.asm
interrupt.o: interrupt.asm
	nasm $(ASFLAGS) interrupt.asm
