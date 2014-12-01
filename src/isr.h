// In The Name Of God
// ========================================
// * File Name : isr-h.c
// 
// * Creation Date : 01-12-2014
//
// * Last Modified : Mon 01 Dec 2014 08:34:00 AM IRST
//
// * Created By : Parham Alvani (parham.alvani@gmail.com)
// =======================================
#include "common.h"

// A few defines to make life a little easier
#define IRQ0 32
#define IRQ1 33
#define IRQ2 34
#define IRQ3 35
#define IRQ4 36
#define IRQ5 37
#define IRQ6 38
#define IRQ7 39
#define IRQ8 40
#define IRQ9 41
#define IRQ10 42
#define IRQ11 43
#define IRQ12 44
#define IRQ13 45
#define IRQ14 46
#define IRQ15 47

typedef struct registers{
	u32int ds;                  // Data segment selector
    	u32int edi, esi, ebp, esp, ebx, edx, ecx, eax; // Pushed by pusha.
    	u32int int_no, err_code;    // Interrupt number and error code (if applicable)
    	u32int eip, cs, eflags, useresp, ss; // Pushed by the processor automatically.
} registers_t;

// Enables registration of callbacks for interrupts or IRQs.
// For IRQs, to ease confusion, use the #defines above as the
// first parameter.
typedef void (*isr_t)(registers_t);
void register_interrupt_handler(u8int n, isr_t handler);
