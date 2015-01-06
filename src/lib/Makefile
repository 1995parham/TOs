OBJ=io.o monitor.o printf.o string.o
ASFLAGS=-felf32
CFLAGS=-Wall -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -I../include/

lib.a: $(OBJ)
	ar rcs lib.a $(OBJ)
	
io.o: io.asm
	nasm $(ASFLAGS) io.asm

clean:
	rm lib.a $(OBJ);
