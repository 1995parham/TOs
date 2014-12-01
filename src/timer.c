// In The Name Of God
// ========================================
// * File Name : timer.c
// 
// * Creation Date : 01-12-2014
//
// * Last Modified : Tue 02 Dec 2014 12:56:57 AM IRST
//
// * Created By : Parham Alvani (parham.alvani@gmail.com)
// =======================================
#include "timer.h"
#include "isr.h"
#include "monitor.h"

static uint32_t tick = 0;

static void timer_callback(registers_t regs){
	tick++;
	// Timer work well so i commented test command
    	// monitor_write("Tick: ");
    	// monitor_write_dec(tick);
    	// monitor_write("\n");
}

void init_timer(uint32_t frequency){
    	// Firstly, register our timer callback.
    	register_interrupt_handler(IRQ0, &timer_callback);

    	// The value we send to the PIT is the value to divide it's input clock
    	// (1193180 Hz) by, to get our required frequency. Important to note is
    	// that the divisor must be small enough to fit into 16-bits.
    	uint32_t divisor = 1193180 / frequency;

    	// Send the command byte.
    	outb(0x43, 0x36);

    	// Divisor has to be sent byte-wise, so split here into upper/lower bytes.
    	uint8_t l = (uint8_t)(divisor & 0xFF);
    	uint8_t h = (uint8_t)((divisor>>8) & 0xFF);

    	// Send the frequency divisor.
    	outb(0x40, l);
    	outb(0x40, h);
}

void timer_wait(uint32_t t){
	uint32_t local_tick = tick;
	while(tick < local_tick + t){
	}
}
