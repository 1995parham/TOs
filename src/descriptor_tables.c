/*
 * In The Name Of God
 * ========================================
 * [] File Name : descriptor_tables.c
 *
 * [] Creation Date : 27-12-2014
 *
 * [] Last Modified : Thu 08 Jan 2015 10:30:19 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdint.h>
#include <asm/io.h>
#include <string.h>
#include "gdt.h"
#include "descriptor_tables.h"

// Lets us access our ASM functions from our C code.
extern void gdt_flush(uint32_t);
extern void idt_flush(uint32_t);

// Internal function prototypes.
static void init_gdt();
static void init_idt();
static void gdt_set_gate(int32_t, uint32_t, uint32_t, uint8_t, uint8_t);
static void idt_set_gate(uint8_t, uint32_t, uint16_t, uint8_t);

gdt_entry_t gdt_entries[5];
gdt_ptr_t   gdt_ptr;
idt_entry_t idt_entries[256];
idt_ptr_t   idt_ptr;

// Initialisation routine - zeroes all the interrupt service routines,
// initialises the GDT and IDT.
void init_descriptor_tables(){

    // Initialise the global descriptor table.
    init_gdt();
    // Initialise the interrupt descriptor table.
    init_idt();

}

static void init_gdt(){
    	gdt_ptr.limit = (sizeof(gdt_entry_t) * 5) - 1;
    	gdt_ptr.base  = (uint32_t)&gdt_entries;

    	gdt_set_gate(0, 0, 0, 0, 0);                /* Null segment */
    	gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); /* Code segment */
    	gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); /* Data segment */
    	gdt_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); /* User mode code segment */
    	gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); /* User mode data segment */

    	gdt_flush((uint32_t)&gdt_ptr);
}

// Set the value of one GDT entry.
static void gdt_set_gate(int32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran){
    	gdt_entries[num].base_low    = (base & 0xFFFF);
    	gdt_entries[num].base_middle = (base >> 16) & 0xFF;
    	gdt_entries[num].base_high   = (base >> 24) & 0xFF;

    	gdt_entries[num].limit_low   = (limit & 0xFFFF);
    	gdt_entries[num].granularity = (limit >> 16) & 0x0F;

    	gdt_entries[num].granularity |= gran & 0xF0;
    	gdt_entries[num].access      = access;
}

static void init_idt(){
    	idt_ptr.limit = sizeof(idt_entry_t) * 256 -1;
    	idt_ptr.base  = (uint32_t)&idt_entries;

    	memset(&idt_entries, 0, sizeof(idt_entry_t) * 256);
	
	// Remap the irq table.
	outb(0x20, 0x11);
	outb(0xA0, 0x11);
        outb(0x21, 0x20);
	outb(0xA1, 0x28);
	outb(0x21, 0x04);
        outb(0xA1, 0x02);
        outb(0x21, 0x01);
        outb(0xA1, 0x01);
        outb(0x21, 0x0);
        outb(0xA1, 0x0);

    	idt_set_gate( 0, (uint32_t)isr0 , 0x08, 0x8E);
    	idt_set_gate( 1, (uint32_t)isr1 , 0x08, 0x8E);
    	idt_set_gate( 2, (uint32_t)isr2 , 0x08, 0x8E);
    	idt_set_gate( 3, (uint32_t)isr3 , 0x08, 0x8E);
    	idt_set_gate( 4, (uint32_t)isr4 , 0x08, 0x8E);
    	idt_set_gate( 5, (uint32_t)isr5 , 0x08, 0x8E);
    	idt_set_gate( 6, (uint32_t)isr6 , 0x08, 0x8E);
    	idt_set_gate( 7, (uint32_t)isr7 , 0x08, 0x8E);
    	idt_set_gate( 8, (uint32_t)isr8 , 0x08, 0x8E);
    	idt_set_gate( 9, (uint32_t)isr9 , 0x08, 0x8E);
    	idt_set_gate(10, (uint32_t)isr10, 0x08, 0x8E);
    	idt_set_gate(11, (uint32_t)isr11, 0x08, 0x8E);
    	idt_set_gate(12, (uint32_t)isr12, 0x08, 0x8E);
    	idt_set_gate(13, (uint32_t)isr13, 0x08, 0x8E);
    	idt_set_gate(14, (uint32_t)isr14, 0x08, 0x8E);
    	idt_set_gate(15, (uint32_t)isr15, 0x08, 0x8E);
    	idt_set_gate(16, (uint32_t)isr16, 0x08, 0x8E);
    	idt_set_gate(17, (uint32_t)isr17, 0x08, 0x8E);
    	idt_set_gate(18, (uint32_t)isr18, 0x08, 0x8E);
    	idt_set_gate(19, (uint32_t)isr19, 0x08, 0x8E);
    	idt_set_gate(20, (uint32_t)isr20, 0x08, 0x8E);
    	idt_set_gate(21, (uint32_t)isr21, 0x08, 0x8E);
    	idt_set_gate(22, (uint32_t)isr22, 0x08, 0x8E);
    	idt_set_gate(23, (uint32_t)isr23, 0x08, 0x8E);
    	idt_set_gate(24, (uint32_t)isr24, 0x08, 0x8E);
    	idt_set_gate(25, (uint32_t)isr25, 0x08, 0x8E);
    	idt_set_gate(26, (uint32_t)isr26, 0x08, 0x8E);
    	idt_set_gate(27, (uint32_t)isr27, 0x08, 0x8E);
    	idt_set_gate(28, (uint32_t)isr28, 0x08, 0x8E);
    	idt_set_gate(29, (uint32_t)isr29, 0x08, 0x8E);
    	idt_set_gate(30, (uint32_t)isr30, 0x08, 0x8E);
    	idt_set_gate(31, (uint32_t)isr31, 0x08, 0x8E);
	idt_set_gate(32, (uint32_t)irq0, 0x08, 0x8E);
	idt_set_gate(33, (uint32_t)irq1, 0x08, 0x8E);
	idt_set_gate(34, (uint32_t)irq2, 0x08, 0x8E);
	idt_set_gate(35, (uint32_t)irq3, 0x08, 0x8E);
	idt_set_gate(36, (uint32_t)irq4, 0x08, 0x8E);
	idt_set_gate(37, (uint32_t)irq5, 0x08, 0x8E);
	idt_set_gate(38, (uint32_t)irq6, 0x08, 0x8E);
	idt_set_gate(39, (uint32_t)irq7, 0x08, 0x8E);
	idt_set_gate(40, (uint32_t)irq8, 0x08, 0x8E);
	idt_set_gate(41, (uint32_t)irq9, 0x08, 0x8E);
	idt_set_gate(42, (uint32_t)irq10, 0x08, 0x8E);
	idt_set_gate(43, (uint32_t)irq11, 0x08, 0x8E);
	idt_set_gate(44, (uint32_t)irq12, 0x08, 0x8E);
	idt_set_gate(45, (uint32_t)irq13, 0x08, 0x8E);
	idt_set_gate(46, (uint32_t)irq14, 0x08, 0x8E);
	idt_set_gate(47, (uint32_t)irq15, 0x08, 0x8E);

    	idt_flush((uint32_t)&idt_ptr);
}

static void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags)
{
    	idt_entries[num].base_low = base & 0xFFFF;
    	idt_entries[num].base_high = (base >> 16) & 0xFFFF;

    	idt_entries[num].sel     = sel;
    	idt_entries[num].always0 = 0;
    	// We must uncomment the OR below when we get to using user-mode.
    	// It sets the interrupt gate's privilege level to 3.
    	idt_entries[num].flags   = flags /* | 0x60 */;
}
