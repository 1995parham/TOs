/*
 * In The Name Of God
 * ========================================
 * [] File Name : kernel.h
 *
 * [] Creation Date : 06-01-2015
 *
 * [] Last Modified : Tue 06 Jan 2015 10:10:33 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef KERNEL_H
#define KERNEL_H

#include <stdint.h>

/*
 * kernel code start address
*/
extern uint32_t code;

/*
 * kernel bss end address
*/
extern uint32_t end;

/*
 * kernel entry point address
*/
extern uint32_t start;

#endif
