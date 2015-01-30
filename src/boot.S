/*
 * In The Name Of God
 * ========================================
 * [] File Name : boot.S
 *
 * [] Creation Date : 30-01-2015
 *
 * [] Last Modified : Fri 30 Jan 2015 08:07:11 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
.equ MBOOT_PAGE_ALIGN, 1<<0		# Load kernel and modules on a page boundary
.equ MBOOT_MEM_INFO, 1<<1		# Provide your kernel with memory info
.equ MBOOT_HEADER_MAGIC, 0x1BADB002	# Multiboot Magic value

/*
 * NOTE: We do not use MBOOT_AOUT_KLUDGE. It means that GRUB does not
 * pass us a symbol table.
*/

.equ MBOOT_HEADER_FLAGS, MBOOT_PAGE_ALIGN | MBOOT_MEM_INFO
.equ MBOOT_CHECKSUM, -(MBOOT_HEADER_MAGIC + MBOOT_HEADER_FLAGS)

.global mboot                  	# Make 'mboot' accessible from C.
.extern code                 	# Start of the '.text' section.
.extern bss                    	# Start of the .bss section.
.extern end                   	# End of the last loadable section.

mboot:
/*
 * typedef struct multiboot_header {
 *	unsigned long magic;
 *	unsigned long flags;
 *	unsigned long checksum;
 *	unsigned long header_addr;
 *	unsigned long load_addr;
 *	unsigned long load_end_addr;
 *	unsigned long bss_end_addr;
 *	unsigned long entry_addr;
 * } multiboot_header_t;
*/

.long  MBOOT_HEADER_MAGIC	
.long  MBOOT_HEADER_FLAGS
.long MBOOT_CHECKSUM
.long  mboot
.long  code
.long bss
.long  end
.long  start

.global start                  	# Kernel entry point.
.extern kmain                   # This is the entry point of our C code

start:
	pushl	%ebx                   	# Load multiboot header location

	/* Execute the kernel: */
	cli                         	# Disable interrupts.
	call	kmain			# call our main() function.
	jmp	.			# Enter an infinite loop, to stop the processor
                              		# executing whatever rubbish is in the memory
                              		# after our kernel! 
