// In the name of god
// main.c -- TOs kernel main c file
//	Parham Alvani(parham.alvani@gmail.com)
//	14 November 2014

#include "monitor.h"
#include "descriptor_tables.h"
#include "timer.h"
#include "multiboot.h"

int main(multiboot_info_t *mboot_ptr) {
	monitor_clear();

	monitor_write("Welcome to TOs(Tiny OS) written by\n");
	monitor_write("Parham Alvani(parham.alvani@gmail.com)\n");
	monitor_write("Navid Mashayekhi(navidmsk@gmail.com)\n");
	monitor_write("Mohammad Reza Mahboubi Ardakani(mrmahboubi@gmail.com)\n");
	
	init_descriptor_tables();
	
	asm volatile ("int $0x3");
	asm volatile ("sti");
	
	init_timer(50);	//Initialise timer to 50Hz

	return 0xDEADBABA;
} 
