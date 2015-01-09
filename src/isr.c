/*
 * In The Name Of God
 * ========================================
 * [] File Name : isr.c
 *
 * [] Creation Date : 27-12-2014
 *
 * [] Last Modified : Fri 09 Jan 2015 06:31:24 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdint.h>
#include <io.h>
#include <stdio.h>
#include "isr.h"

isr_t interrupt_handlers[256];

void register_interrupt_handler(uint8_t n, isr_t handler)
{
	interrupt_handlers[n] = handler;
}

/*
 * This gets called from our ASM interrupt handler stub.
*/
void isr_handler(registers_t regs)
{
	printf("Recieved interrupt: %d\n", regs.int_no);

	/* If we have a handler, we call it !! */
	if (interrupt_handlers[regs.int_no] != 0) {
		isr_t handler = interrupt_handlers[regs.int_no];

		handler(regs);
	}
}

/*
 * This gets called from our ASM interrupt handler stub.
*/
void irq_handler(registers_t regs)
{
	/*
	 * Send an EOI (end of interrupt) signal to the PICs.
	 * If this interrupt involved the slave.
	*/
	if (regs.int_no >= 40) {
		/* Send reset signal to slave. */
		outb(0xA0, 0x20);
	}
	/* Send reset signal to master. (As well as slave, if necessary). */
	outb(0x20, 0x20);

	/* If we have a handler, we call it !! */
	if (interrupt_handlers[regs.int_no] != 0) {
		isr_t handler = interrupt_handlers[regs.int_no];

		handler(regs);
	}
}
