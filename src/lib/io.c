/*
 * In The Name Of God
 * ========================================
 * [] File Name : io.c
 *
 * [] Creation Date : 09-01-2015
 *
 * [] Last Modified : Fri 09 Jan 2015 06:29:04 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/

#include <stdint.h>

/*
 * NASM:
 * 	mov al, value
 * 	mov dx, port
 * 	out dx, al
 */
void outb(uint16_t port, uint8_t value)
{
	__asm__("outb %0, %1"
		:
		: "a" (value), "d" (port)
	       );
}

uint8_t inb(uint16_t port)
{
	register uint8_t __res;
	__asm__("inb %1,%0"
		: "=a" (__res)
		: "d" (port)
	       );
	return __res;
}

uint16_t inw(uint16_t port)
{	
	register uint8_t __res;
	__asm__("inb %1,%0"
		: "=a" (__res)
		: "d" (port)
	       );
	return __res;
}


