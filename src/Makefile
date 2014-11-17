SOURCES=boot.o main.o common.o common.asm.o monitor.o descriptor_tables.o isr.o gdt.o interrupt.o

CFLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector
LDFLAGS=-melf_i386 -Tlink.ld
ASFLAGS=-felf32

all: $(SOURCES) link 

clean:
	-rm *.o kernel

link:
	ld $(LDFLAGS) -o kernel $(SOURCES)

boot.o:
	nasm $(ASFLAGS) boot.asm
common.asm.o:
	nasm $(ASFLAGS) -o common.asm.o common.asm
gdt.o:
	nasm $(ASFLAGS) gdt.asm
interrupt.o:
	nasm $(ASFLAGS) interrupt.asm
