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
LIB=lib/Tlibc.a
CFLAGS=-Wall -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -Iinclude/
LDFLAGS=-melf_i386 -Tlink.ld
ASFLAGS=$(CFLAGS)
ASMFLAGS=-felf

all: kernel

kernel: $(OBJ) $(LIB)
	ld $(LDFLAGS) -o kernel $(OBJ) $(LIB)
lib/Tlibc.a:
	make Tlibc.a -C lib/
boot.o:
main.o: descriptor_tables.h timer.h sound.h exception.h paging.h
descriptor_tables.o:
isr.o:
timer.o:
sound.o:
exception.o:
paging.o: paging.h isr.h

# GNU make cannot compile assembly files with nasm explicitly
# TODO: change nasm syntax into gas syntax
gdt.o: gdt.asm gdt.h
	nasm $(ASMFLAGS) gdt.asm
interrupt.o: interrupt.asm
	nasm $(ASMFLAGS) interrupt.asm

.PHONY: clean
clean:
	-rm $(OBJ) kernel
	make clean -C lib/
