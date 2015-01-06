/*
 * In The Name Of God
 * ========================================
 * [] File Name : isr.h
 *
 * [] Creation Date : 27-12-2014
 *
 * [] Last Modified : Tue 06 Jan 2015 04:52:20 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef ISR_H
#define ISR_H
#include <stdint.h>

/* A few defines to make life a little easier */
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

/*
 * @ds: Data segment selector
 *
 * @edi, esi, ebp, esp, ebx, edx, ecx, eax:
 * Pushed by pusha
 *
 * @int_no: Interrupt number
 *
 * @err_code: Error code
 *
 * @eip, cs, eflags, user_esp, ss:
 * Pushed by processor automatically
*/
typedef struct registers {
	uint32_t ds;
	uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
	uint32_t int_no, err_code;
	uint32_t eip, cs, eflags, useresp, ss;
} registers_t;

/*
 * Enables registration of callbacks for interrupts or IRQs.
 * For IRQs, to ease confusion, use the #defines above as the
 * first parameter.
*/
typedef void (*isr_t)(registers_t);

void register_interrupt_handler(uint8_t n, isr_t handler);

#endif
