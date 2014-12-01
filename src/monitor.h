// In The Name Of God
// ========================================
// * File Name : monitor.h
// 
// * Creation Date : 01-12-2014
//
// * Last Modified : Tue 02 Dec 2014 12:51:04 AM IRST
//
// * Created By : Parham Alvani (parham.alvani@gmail.com)
// =======================================
#ifndef MONITOR_H
#define MONITOR_H

#include "common.h"

// Write a single character out to the screen.
void monitor_put(char c);

// Clear the screen to all black.
void monitor_clear();

// Output a null-terminated ASCII string to the monitor.
void monitor_write(char *c);

void monitor_write_hex(uint32_t n);

void monitor_write_dec(uint32_t n);
#endif // MONITOR_H
