;
;	common.asm---common assembly function for common.h header file
;	Parham Alvani(parham.alvani@gmail.com)
;	14 November 2015

BITS 32
section .text
	global outb
	global inb
outb:
	pop edx		; uint16 port
	pop eax		; uint8  value
	out dx, al
	leave
	ret
inb:
	pop edx		; uint16 port
	xor ax, ax
	in al, dx
	leave
	ret
inw:
	pop edx		; uint16 port
	xor ax, ax
	in ax, dx
	leave
	ret
