// In The Name Of God
// ========================================
// * File Name : exception.c
// 
// * Creation Date : 01-12-2014
//
// * Last Modified : Tue 02 Dec 2014 12:34:56 AM IRST
//
// * Created By : Parham Alvani (parham.alvani@gmail.com)
// =======================================
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
