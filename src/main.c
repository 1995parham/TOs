/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 27-12-2014
 *
 * [] Last Modified : Sat 31 Jan 2015 01:21:51 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <multiboot.h>
#include <monitor.h>
#include <stdio.h>
#include <kernel.h>
#include <kmalloc.h>
#include <string.h>

#include "descriptor_tables.h"
#include "timer.h"
#include "sound.h"
#include "exception.h"
#include "paging.h"

int kmain(multiboot_info_t *mboot_ptr)
{
	cls();

	printf("Welcome to TOs(Tiny OS) written by\n");
	printf("Parham Alvani(parham.alvani@gmail.com)\n");
	printf("Navid Mashayekhi(navidmsk@gmail.com)\n");
	printf("Mohammad Reza Mahboubi Ardakani(mrmahboubi@gmail.com)\n");
	
	printf("Memupper: %ld\n", mboot_ptr->mem_upper);
	printf("Memlower: %ld\n", mboot_ptr->mem_lower);
	
	printf("Kernel code start @ %p\n", &code);
	printf("Kernel end @ %p\n", &end);

	init_descriptor_tables();
	
	asm volatile ("sti");
	
	init_exception();
	/* Initialise timer to 50Hz */
	init_timer(50);	

	beep();
	
	initialise_paging();
	printf("Hello, paging world!\n");
	
	return 0xDEADBABA;
} 
