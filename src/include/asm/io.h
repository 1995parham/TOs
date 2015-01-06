/*
 * In The Name Of God
 * ========================================
 * [] File Name : io.h
 *
 * [] Creation Date : 27-12-2014
 *
 * [] Last Modified : Tue 06 Jan 2015 04:31:16 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef IO_H
#define IO_H

void outb(uint16_t port, uint8_t value);
uint8_t inb(uint16_t port);
uint16_t inw(uint16_t port);

#endif
