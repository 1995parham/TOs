SOURCES=boot.o

CFLAGS=
LDFLAGS=-Tlink.ld
ASFLAGS=-felf

all: $(SOURCES) link 

clean:
 »  -rm *.o kernel

link:
 »  ld $(LDFLAGS) -o kernel $(SOURCES)

.s.o:
 »  nasm $(ASFLAGS) $<
