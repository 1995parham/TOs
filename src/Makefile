# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 10-01-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================
OBJ=boot.o main.o descriptor_tables.o isr.o gdt.o interrupt.o timer.o sound.o exception.o \
    paging.o
LIB=lib/lib.a
CFLAGS=-Wall -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -Iinclude/
LDFLAGS=-melf_i386 -Tlink.ld
ASFLAGS=-felf32

all: kernel

kernel: $(OBJ) $(LIB)
	ld $(LDFLAGS) -o kernel $(OBJ) $(LIB)
lib/lib.a:
	make lib.a -C lib/
main.o:
descriptor_tables.o:
isr.o:
timer.o:
sound.o:
exception.o:
paging.o: paging.h

# GNU make cannot compile assembly files with nasm explicitly
boot.o: boot.asm
	nasm $(ASFLAGS) boot.asm
gdt.o: gdt.asm gdt.h
	nasm $(ASFLAGS) gdt.asm
interrupt.o: interrupt.asm
	nasm $(ASFLAGS) interrupt.asm

.PHONY: clean
clean:
	-rm $(OBJ) kernel
	make clean -C lib/
