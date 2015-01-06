OBJ=io.o
ASFLAGS=-felf32

lib.a: $(OBJ)
	ar rcs lib.a $(OBJ)
	
io.o: io.asm
	nasm $(ASFLAGS) io.asm

clean:
	rm lib.a $(OBJ);
