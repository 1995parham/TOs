/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 27-12-2014
 *
 * [] Last Modified : Sat 27 Dec 2014 03:29:46 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include "monitor.h"
#include "descriptor_tables.h"
#include "timer.h"
#include "multiboot.h"
#include "sound.h"

int main(multiboot_info_t *mboot_ptr) {
	monitor_clear();

	monitor_write("Welcome to TOs(Tiny OS) written by\n");
	monitor_write("Parham Alvani(parham.alvani@gmail.com)\n");
	monitor_write("Navid Mashayekhi(navidmsk@gmail.com)\n");
	monitor_write("Mohammad Reza Mahboubi Ardakani(mrmahboubi@gmail.com)\n");
	
	init_descriptor_tables();
	
	asm volatile ("sti");
	
	init_timer(50);	//Initialise timer to 50Hz
	init_exception();

	beep();

	return 0xDEADBABA;
} 
