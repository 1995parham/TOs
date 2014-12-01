// In The Name Of God
// ========================================
// * File Name : monitor.h
// 
// * Creation Date : 01-12-2014
//
// * Last Modified : Mon 01 Dec 2014 08:39:00 AM IRST
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

#endif // MONITOR_H
