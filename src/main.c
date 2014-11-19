// In the name of god
// main.c -- TOs kernel main c file
//	Parham Alvani(parham.alvani@gmail.com)
//	14 November 2015

#include "monitor.h"
#include "descriptor_tables.h"

int main(struct multiboot *mboot_ptr)
{
	// All our initialisation calls will go in here.
	monitor_clear();

	monitor_write("Welcome to TOs(Tiny OS) written by\n");
	monitor_write("Parham Alvani(parham.alvani@gmail.com)\n");
	monitor_write("Navid Mashayekhi\n");
	monitor_write("Mohammad Reza Mahboubi Ardakani\n");
	
	init_descriptor_tables();
	
	asm volatile ("int $0x3");

	return 0xDEADBABA;
} 
