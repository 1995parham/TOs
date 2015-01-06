; In The Name Of God
; ========================================
; * File Name : gdt.asm
;
; * Creation Date : 01-12-2014
;
; * Last Modified : Tue 06 Jan 2015 04:44:31 AM IRST
;
; * Created By : Parham Alvani (parham.alvani@gmail.com)
; =======================================
global gdt_flush    	  ; Allows the C code to call gdt_flush().
gdt_flush:
    	mov eax, [esp+4]  ; Get the pointer to the GDT, passed as a parameter.
    	lgdt [eax]        ; Load the new GDT pointer

	mov ax, 0x10      ; 0x10 is the offset in the GDT to our data segment
	mov ds, ax        ; Load all data segment selectors
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	jmp 0x08:.flush   ; 0x08 is the offset to our code segment: Far jump!
.flush:
	ret

global idt_flush    	  ; Allows the C code to call idt_flush().

idt_flush:
    mov eax, [esp+4]  	  ; Get the pointer to the IDT, passed as a parameter.
    lidt [eax]        	  ; Load the IDT pointer.
    ret
