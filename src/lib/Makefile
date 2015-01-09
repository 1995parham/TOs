OBJ=io.o monitor.o printf.o kmalloc.o
ASFLAGS=-felf32
CFLAGS=-Wall -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -I../include/

lib.a: $(OBJ)
	ar rcs lib.a $(OBJ)
clean:
	rm lib.a $(OBJ);
