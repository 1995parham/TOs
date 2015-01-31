OBJ=io.o monitor.o printf.o kmalloc.o
CFLAGS=-Wall -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -I../include/

Tlibc.a: $(OBJ)
	ar rcs Tlibc.a $(OBJ)
clean:
	rm Tlibc.a $(OBJ)
