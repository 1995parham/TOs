; In The Name Of God
; ========================================
; * File Name : boot.asm
; 
; * Creation Date : 01-12-2014
;
; * Last Modified : Thu 08 Jan 2015 01:34:09 PM IRST
;
; * Created By : Parham Alvani (parham.alvani@gmail.com)
; =======================================

MBOOT_PAGE_ALIGN    equ 1<<0    	; Load kernel and modules on a page boundary
MBOOT_MEM_INFO      equ 1<<1    	; Provide your kernel with memory info
MBOOT_HEADER_MAGIC  equ 0x1BADB002 	; Multiboot Magic value

; NOTE: We do not use MBOOT_AOUT_KLUDGE. It means that GRUB does not
; pass us a symbol table.

MBOOT_HEADER_FLAGS  equ MBOOT_PAGE_ALIGN | MBOOT_MEM_INFO
MBOOT_CHECKSUM      equ -(MBOOT_HEADER_MAGIC + MBOOT_HEADER_FLAGS)


BITS 32                       	; All instructions should be 32-bit.

global mboot                  	; Make 'mboot' accessible from C.
extern code                 	; Start of the '.text' section.
extern bss                    	; Start of the .bss section.
extern end                   	; End of the last loadable section.

mboot:

; typedef struct multiboot_header {
;	unsigned long magic;
; 	unsigned long flags;
; 	unsigned long checksum;
;	unsigned long header_addr;                                                                                                                                                              ; 	unsigned long load_addr;
;	unsigned long load_end_addr;
;	unsigned long bss_end_addr;
;	unsigned long entry_addr;
; } multiboot_header_t;

dd  MBOOT_HEADER_MAGIC	
dd  MBOOT_HEADER_FLAGS
dd  MBOOT_CHECKSUM
dd  mboot
dd  code
dd  bss
dd  end
dd  start

global start                  	; Kernel entry point.
extern main                   	; This is the entry point of our C code

start:
	push ebx                   	; Load multiboot header location

	; Execute the kernel:
	cli                         	; Disable interrupts.
	call main                   	; call our main() function.
	jmp $                       	; Enter an infinite loop, to stop the processor
                              		; executing whatever rubbish is in the memory
                              		; after our kernel! 
