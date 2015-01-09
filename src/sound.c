/*
 * In The Name Of God
 * ========================================
 * [] File Name : sound.c
 *
 * [] Creation Date : 27-12-2014
 *
 * [] Last Modified : Fri 09 Jan 2015 06:31:45 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdint.h>
#include <io.h>
#include "sound.h"
#include "timer.h"

/*
 * Play sound using built in speaker
*/
static void play_sound(uint32_t frequency)
{
	uint32_t divisor;
	uint8_t PB;

	/* Set the PIT counter 2 to the desired frequency */
	divisor = 1193180 / frequency;
	outb(0x43, 0xb6);
	outb(0x42, (uint8_t) (divisor) );
	outb(0x42, (uint8_t) (divisor >> 8));
	
	/*
	 * Turn the speaker on with setting PB0 and PB1 in
	 * port 0x61
	 *
	 * 3 = 00000011
	*/
	PB = inb(0x61);
	if (PB != (PB | 3)){
		outb(0x61, PB | 3);
	}
}

/*
 * make it shutup
*/
static void nosound(void)
{
	/*
	 * Turn the speaker off with unsetting PB0 and PB1 in
	 * port 0x61
	 *
	 * 0xFC = 11111100
	*/
	uint8_t PB = inb(0x61) & 0xFC;
	outb(0x61, PB);
}

/*
 * Make a beep
*/
void beep(void)
{
	play_sound(1000);
	timer_wait(10);
	nosound();
}
