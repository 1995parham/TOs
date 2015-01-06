/*
 * In The Name Of God
 * ========================================
 * [] File Name : monitor.h
 *
 * [] Creation Date : 27-12-2014
 *
 * [] Last Modified : Tue 06 Jan 2015 09:12:49 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef MONITOR_H
#define MONITOR_H

#include <stdint.h>

/*
 * Write a single character out to the screen.
*/
void putc(char c);

/*
 * Clear the screen to all black.
*/
void cls(void);

/*
 * Output a null-terminated ASCII string to the monitor.
*/
void puts(char *c);

void monitor_write_hex(uint32_t n);

void monitor_write_dec(uint32_t n);

#endif
