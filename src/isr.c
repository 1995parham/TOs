/*
 * In The Name Of God
 * ========================================
 * [] File Name : isr.c
 *
 * [] Creation Date : 27-12-2014
 *
 * [] Last Modified : Tue 06 Jan 2015 09:05:41 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdint.h>
#include <asm/io.h>
#include <monitor.h>
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
	puts("recieved interrupt: ");
	monitor_write_dec(regs.int_no);
	putc('\n');

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

	if (interrupt_handlers[regs.int_no] != 0) {
		isr_t handler = interrupt_handlers[regs.int_no];

		handler(regs);
	}
}
