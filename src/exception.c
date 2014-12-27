/*
 * In The Name Of God
 * ========================================
 * [] File Name : exception.c
 *
 * [] Creation Date : 27-12-2014
 *
 * [] Last Modified : Sat 27 Dec 2014 03:27:54 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include "exception.h"
#include "isr.h"
#include "monitor.h"

static void exception_callback_6(registers_t regs){
	monitor_write("Invalid Opcode\n");
}

static void exception_callback_3(registers_t regs){
	monitor_write("Breakpoint Occur\n");
}

void init_exception(){
	register_interrupt_handler(6, &exception_callback_6);	
	register_interrupt_handler(3, &exception_callback_3);	
}
