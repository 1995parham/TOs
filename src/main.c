#include "monitor.h"

int main(struct multiboot *mboot_ptr)
{
	// All our initialisation calls will go in here.
	monitor_clear();

	monitor_write("Welcome to TOS(Tiny OS) written by\n");
	monitor_write("Parham Alvani(parham.alvani@gmail.com)\n");
	monitor_write("Navid Mashayekhi\n");
	monitor_write("Mohammad Reza Mahboubi Ardakani\n");

	return 0xDEADBABA;
} 
