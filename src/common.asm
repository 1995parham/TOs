; In the name of god
; common.asm -- common assembly function for common.h header file
;	Parham Alvani(parham.alvani@gmail.com)
;	14 November 2014

BITS 32
section .text
	global outb
	global inb
outb:
	push ebp
	mov ebp, esp

	mov edx, [ebp + 8]		; uint16 port
	mov eax, [ebp + 12]		; uint8  value
	out dx, al
	
	pop ebp
	ret
inb:
	push ebp
	mov ebp, esp

	mov edx, [ebp + 8]		; uint16 port
	xor ax, ax
	in al, dx
	
	pop ebp
	ret
inw:
	push ebp
	mov ebp, esp
	
	mov edx, [ebp + 8]		; uint16 port
	xor ax, ax
	in ax, dx
	
	pop ebp
	ret
