/*
 * In The Name Of God
 * ========================================
 * [] File Name : exception.c
 *
 * [] Creation Date : 27-12-2014
 *
 * [] Last Modified : Tue 06 Jan 2015 08:19:24 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include "exception.h"
#include "isr.h"
#include "monitor.h"

static void exception_callback_6(registers_t regs){
	puts("Invalid Opcode\n");
}

static void exception_callback_3(registers_t regs){
	puts("Breakpoint Occur\n");
}

void init_exception(){
	register_interrupt_handler(6, &exception_callback_6);	
	register_interrupt_handler(3, &exception_callback_3);	
}
