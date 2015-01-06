/*
 * In The Name Of God
 * ========================================
 * [] File Name : sound.c
 *
 * [] Creation Date : 27-12-2014
 *
 * [] Last Modified : Tue 06 Jan 2015 05:02:24 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdint.h>
#include <asm/io.h>
#include "sound.h"
#include "timer.h"

/*
 * Play sound using built in speaker
*/
static void play_sound(uint32_t nFrequence) {
	uint32_t Div;
	uint8_t tmp;

	/* Set the PIT to the desired frequency */
	Div = 1193180 / nFrequence;
	outb(0x43, 0xb6);
	outb(0x42, (uint8_t) (Div) );
	outb(0x42, (uint8_t) (Div >> 8));
	
	/* And play the sound using the PC speaker */
	tmp = inb(0x61);
	if (tmp != (tmp | 3)){
		outb(0x61, tmp | 3);
	}
}

/*
 * make it shutup
*/
static void nosound(){
	uint8_t tmp = inb(0x61) & 0xFC;
	outb(0x61, tmp);
}

/*
 * Make a beep
*/
void beep(){
	play_sound(1000);
	timer_wait(10);
	nosound();
}
