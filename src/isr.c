// In The Name Of God
// ========================================
// * File Name : isr.c
// 
// * Creation Date : 01-12-2014
//
// * Last Modified : Mon 01 Dec 2014 08:33:47 AM IRST
//
// * Created By : Parham Alvani (parham.alvani@gmail.com)
// =======================================
#include "common.h"
#include "isr.h"
#include "monitor.h"

isr_t interrupt_handlers[256];

void register_interrupt_handler(u8int n, isr_t handler){
	interrupt_handlers[n] = handler;
}

// This gets called from our ASM interrupt handler stub.
void isr_handler(registers_t regs){
    
	monitor_write("recieved interrupt: ");
    	monitor_write_dec(regs.int_no);
    	monitor_put('\n');

    	if (interrupt_handlers[regs.int_no] != 0){
        	isr_t handler = interrupt_handlers[regs.int_no];
        	handler(regs);
    	}
}

// This gets called from our ASM interrupt handler stub.
void irq_handler(registers_t regs){
    
	// Send an EOI (end of interrupt) signal to the PICs.
    	// If this interrupt involved the slave.
    	if (regs.int_no >= 40){
       		// Send reset signal to slave.
        	outb(0xA0, 0x20);
    	}
    	// Send reset signal to master. (As well as slave, if necessary).
    	outb(0x20, 0x20);

    	if (interrupt_handlers[regs.int_no] != 0){
        	isr_t handler = interrupt_handlers[regs.int_no];
        	handler(regs);
    	}
}
