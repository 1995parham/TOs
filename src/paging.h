/*
 * In The Name Of God
 * ========================================
 * [] File Name : paging.h
 *
 * [] Creation Date : 08-01-2015
 *
 * [] Last Modified : Sat 10 Jan 2015 10:26:37 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef PAGING_H
#define PAGING_H

#include <stdint.h>
#include "isr.h"

#define PAGE_PER_TABLE 1024
#define TOTAL_TABLE 1024

/*
 * @present: Page present in memory
 *
 * @rw: Read-only if clear, read-write if set
 *
 * @user: root level only if clear
 *
 * @accessed: Has the page been accessed since last refresh
 *
 * @dirty: Has the page been written to since last refresh
 *
 * @unused: Amalgamation of unused and reserved bits
 *
 * @frame: Frame address (shifred right 12 bits)
*/
struct page {
	uint32_t present    : 1;
	uint32_t rw         : 1;
	uint32_t user       : 1;
	uint32_t accessed   : 1;
	uint32_t dirty      : 1;
	uint32_t unused     : 7;
	uint32_t frame      : 20;
};

struct page_table {
	struct page pages[PAGE_PER_TABLE];
};

/*
 * @tables: Array of pointers to pagetables.
 *
 * @tablesPhysical: Array of pointers to the pagetables above, but gives their
 * "PHYSICAL" address, for loading into the CR3 register.
 *
 * @physicalAddr: The physical address of tablesPhysical. This comes into play
 * when we got our kernel heap allocation and the "struct directory" may be in
 * a different location in virtual memory.
*/
struct page_directory {
	struct page_table *tables[TOTAL_TABLE];
    	uint32_t tablesPhysical[TOTAL_TABLE];
    	uint32_t physicalAddr;
};

/*
 * Sets up the environment, page directories etc and
 * enables paging.
*/
void initialise_paging(void);

/*
 * Causes the specified page directory to be loaded into the
 * CR3 register.
*/
void switch_page_directory(struct page_directory *new);

/*
 * Retrieves a pointer to the page required.
 * If make == 1, if the page-table in which this page should
 * reside isn't created, create it!
*/
struct page *get_page(uint32_t address, int make, struct page_directory *dir);

/*
 * Handler for page faults.
*/
void page_fault(registers_t regs);

#endif
