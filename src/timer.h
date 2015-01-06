/*
 * In The Name Of God
 * ========================================
 * [] File Name : timer.h
 *
 * [] Creation Date : 27-12-2014
 *
 * [] Last Modified : Tue 06 Jan 2015 08:55:55 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

void timer_wait(uint32_t t);
void init_timer(uint32_t frequency);

#endif
