SOURCES=boot.o main.o common.o monitor.o

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
common.o:
	nasm $(ASFLAGS) common.asm
