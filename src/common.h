// In The Name Of God
// ========================================
// * File Name : common-h.c
// 
// * Creation Date : 01-12-2014
//
// * Last Modified : Mon 01 Dec 2014 08:28:11 AM IRST
//
// * Created By : Parham Alvani (parham.alvani@gmail.com)
// =======================================
#ifndef COMMON_H
#define COMMON_H

// Some nice typedefs, to standardise sizes across platforms.
// These typedefs are written for 32-bit X86.
typedef unsigned int   u32int;
typedef          int   s32int;
typedef unsigned short u16int;
typedef          short s16int;
typedef unsigned char  u8int;
typedef          char  s8int;

void outb(u16int port, u8int value);
u8int inb(u16int port);
u16int inw(u16int port);

#endif // COMMON_H
