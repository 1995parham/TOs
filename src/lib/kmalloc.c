#include <kmalloc.h>
#include <stdint.h>
#include <kernel.h>

/* end is defined in the linker script. */
uint32_t placement_address = (uint32_t) &end;

uint32_t __kmalloc(uint32_t sz, int align, uint32_t *phys)
{
	/*
	* This will eventually call malloc() on the kernel heap.
	* For now, though, we just assign memory at placement_address
	* and increment it by sz. Even when we've coded our kernel
	* heap, this will be useful for use "before" the heap is initialised.
	*     mboot      end
	*     |----------|------------....
	* ... |          |    free space ;-))))
	*     |----------|------------....
	*/
	if (align == 1 && (placement_address & 0xFFFFF000)) {
		/* Align the placement address; */
		placement_address &= 0xFFFFF000;
		placement_address += 0x1000;
	}
	if (phys)
		*phys = placement_address;

	uint32_t tmp = placement_address;

	placement_address += sz;
	return tmp;
}

uint32_t kmalloc_a(uint32_t sz)
{
	return __kmalloc(sz, 1, 0);
}

uint32_t kmalloc_p(uint32_t sz, uint32_t *phys)
{
	return __kmalloc(sz, 0, phys);
}

uint32_t kmalloc_ap(uint32_t sz, uint32_t *phys)
{
	return __kmalloc(sz, 1, phys);
}

uint32_t kmalloc(uint32_t sz)
{
	return __kmalloc(sz, 0, 0);
}
