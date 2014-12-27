/*
 * In The Name Of God
 * ========================================
 * [] File Name : descriptor_tables.h
 *
 * [] Creation Date : 27-12-2014
 *
 * [] Last Modified : Sat 27 Dec 2014 04:24:41 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include "common.h"

/*
 * Initialisation function is publicly accessible.
*/
void init_descriptor_tables(void);


/* This structure contains the value of one GDT entry.
 * We use the attribute 'packed' to tell GCC not to change
 * any of the alignment in the structure.
 * @limit_low: The lower 16 bits of the limit.
 * @base_low: The lower 16 bits of the base.
 * @base_middle: The next 8 bits of the base.
 * @access: Access flags, determine what ring this segment
 * can be used in.
 * @base_high: The last 8 bits of the base.
*/
struct gdt_entry_struct {
	uint16_t limit_low;
	uint16_t base_low;
	uint8_t  base_middle;
	uint8_t  access;
	uint8_t  granularity;
	uint8_t  base_high;
} __attribute__((packed));

/*
 * AMD64 legacy code segement descriptor model
 * 31                 24 23 22 21 20 19   16 15 14   13 12 11 10 9  8  7         0
 * |----------------------------------------|-------------------------------------|
 * |    Base Address    |G |D |= |A |Segment|P |DPL    |1 |1 |C |R |A |   Base    |
 * |       [31:24]      |  |  |= |V |Limit  |  |       |  |  |  |  |  |  Address  | +4
 * |                    |  |  |= |L |[19:16]|  |       |  |  |  |  |  |  [23:16]  |
 * |----------------------------------------|-------------------------------------|
 * |           Base Address[15:0]           |		Segment Limit[15:0]       | +0
 * |----------------------------------------|-------------------------------------|
 *
 * AMD64 segment selector
 * 15                         3 2  1   0
 * |------------------------------------|
 * |    Selector Index[3:15]   |T | RPL |
 * |                           |I |     |
 * |------------------------------------|
 * * TI : Table Indicator
 * * RPL : Request Privilege Leve
*/
typedef struct gdt_entry_struct gdt_entry_t;

/*
 * This struct describes a GDT pointer. It points to the start of
 * our array of GDT entries, and is in the format required by the
 * lgdt instruction.
 * @limit: The upper 16 bits of all selector limits.
 * @base: The address of the first gdt_entry_t struct.
*/
struct gdt_ptr_struct {
	uint16_t limit;
	uint32_t base;
} __attribute__((packed));

typedef struct gdt_ptr_struct gdt_ptr_t;

/*
 * A struct describing an interrupt gate.
 * @base_low: The lower 16 bits of the address to jump to when this
 * interrupt fires.
 * @sel: Kernel segment selector
 * @always0: This must always be zero ;-)
 * @flags: More flags. See documentation.
 * @base_high: The upper 16 bits of the address to jump to.
*/
struct idt_entry_struct {
	uint16_t base_low;
	uint16_t sel;
	uint8_t  always0;
	uint8_t  flags;
	uint16_t base_high;
} __attribute__((packed));

typedef struct idt_entry_struct idt_entry_t;

/* A struct describing a pointer to an array of interrupt handlers.
 * This is in a format suitable for giving to 'lidt'.
 * @base: The address of the first element in our idt_entry_t array.
*/
struct idt_ptr_struct {
	uint16_t limit;
	uint32_t base;
} __attribute__((packed));

typedef struct idt_ptr_struct idt_ptr_t;

/*
 * These extern directives let us access the addresses of our ASM ISR handlers.
*/
extern void isr0(void);
extern void isr1(void);
extern void isr2(void);
extern void isr3(void);
extern void isr4(void);
extern void isr5(void);
extern void isr6(void);
extern void isr7(void);
extern void isr8(void);
extern void isr9(void);
extern void isr10(void);
extern void isr11(void);
extern void isr12(void);
extern void isr13(void);
extern void isr14(void);
extern void isr15(void);
extern void isr16(void);
extern void isr17(void);
extern void isr18(void);
extern void isr19(void);
extern void isr20(void);
extern void isr21(void);
extern void isr22(void);
extern void isr23(void);
extern void isr24(void);
extern void isr25(void);
extern void isr26(void);
extern void isr27(void);
extern void isr28(void);
extern void isr29(void);
extern void isr30(void);
extern void isr31(void);
extern void irq0(void);
extern void irq1(void);
extern void irq2(void);
extern void irq3(void);
extern void irq4(void);
extern void irq5(void);
extern void irq6(void);
extern void irq7(void);
extern void irq8(void);
extern void irq9(void);
extern void irq10(void);
extern void irq11(void);
extern void irq12(void);
extern void irq13(void);
extern void irq14(void);
extern void irq15(void);
