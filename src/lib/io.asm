; In The Name Of God
; ========================================
; * File Name : common.asm
; 
; * Creation Date : 01-12-2014
;
; * Last Modified : Sat 27 Dec 2014 03:59:28 AM IRST
;
; * Created By : Parham Alvani (parham.alvani@gmail.com)
; =======================================

BITS 32
section .text
	global outb
	global inb
	global inw
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
