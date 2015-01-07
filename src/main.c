/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 27-12-2014
 *
 * [] Last Modified : Wed 07 Jan 2015 04:10:12 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <multiboot.h>
#include <monitor.h>
#include <stdio.h>
#include <kernel.h>
#include <kmalloc.h>
#include "descriptor_tables.h"
#include "timer.h"
#include "sound.h"
#include "exception.h"

int main(multiboot_info_t *mboot_ptr)
{
	cls();

	printf("Welcome to TOs(Tiny OS) written by\n");
	printf("Parham Alvani(parham.alvani@gmail.com)\n");
	printf("Navid Mashayekhi(navidmsk@gmail.com)\n");
	printf("Mohammad Reza Mahboubi Ardakani(mrmahboubi@gmail.com)\n");
	
	printf("Memupper: %ld\n", mboot_ptr->mem_upper);
	printf("Memlower: %ld\n", mboot_ptr->mem_lower);
	
	printf("Kernel code start @ %x\n", &code);
	printf("Kernel end @ %x\n", &end);
	printf("Are allocation done @ %x\n", kmalloc(1));


	init_descriptor_tables();
	
	asm volatile ("sti");
	
	init_exception();
	/* Initialise timer to 50Hz */
	init_timer(50);	

	beep();

	return 0xDEADBABA;
} 
