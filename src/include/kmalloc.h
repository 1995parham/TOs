/*
 * In The Name Of God
 * ========================================
 * [] File Name : kmalloc.h
 *
 * [] Creation Date : 06-01-2015
 *
 * [] Last Modified : Tue 06 Jan 2015 10:05:58 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef KMALLOC_H
#define KMALLOC_H

#include <stdint.h>

/*
 * Allocate a chunk of memory, sz in size. If align == 1,
 * the chunk must be page-aligned. If phys != 0, the physical
 * location of the allocated chunk will be stored into phys.
 *
 * This is the internal version of kmalloc. More user-friendly
 * parameter representations are available in kmalloc, kmalloc_a,
 * kmalloc_ap, kmalloc_p.
*/
uint32_t __kmalloc(uint32_t sz, int align, uint32_t *phys);

/*
 * Allocate a chunk of memory, sz in size. The chunk must be
 * page aligned.
*/
uint32_t kmalloc_a(uint32_t sz);

/*
 * Allocate a chunk of memory, sz in size. The physical address
 * is returned in phys. Phys MUST be a valid pointer to u32int!
*/
uint32_t kmalloc_p(uint32_t sz, uint32_t *phys);

/*
 * Allocate a chunk of memory, sz in size. The physical address
 * is returned in phys. It must be page-aligned.
*/
uint32_t kmalloc_ap(uint32_t sz, uint32_t *phys);

/*
 * General allocation function.
*/
uint32_t kmalloc(uint32_t sz);

#endif
