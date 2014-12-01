; In The Name Of God
; ========================================
; * File Name : common.asm
; 
; * Creation Date : 01-12-2014
;
; * Last Modified : Mon 01 Dec 2014 08:47:01 PM IRST
;
; * Created By : Parham Alvani (parham.alvani@gmail.com)
; =======================================

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
