// In The Name Of God
// ========================================
// * File Name : common-h.c
// 
// * Creation Date : 01-12-2014
//
// * Last Modified : Tue 02 Dec 2014 12:58:04 AM IRST
//
// * Created By : Parham Alvani (parham.alvani@gmail.com)
// =======================================
#ifndef COMMON_H
#define COMMON_H

// These typedefs are written for 32-bit X86.
typedef unsigned int   uint32_t;
typedef          int   int32_t;
typedef unsigned short uint16_t;
typedef          short int16_t;
typedef unsigned char  uint8_t;
typedef          char  int8_t;
typedef unsigned long int uint64_t;
typedef          long int int64_t;

// Implemented in common.asm
void outb(uint16_t port, uint8_t value);
uint8_t inb(uint16_t port);
uint16_t inw(uint16_t port);

// Implemented in common.c
void memcpy(uint8_t *dest, const uint8_t *src, uint32_t len);
void memset(uint8_t *dest, uint8_t val, uint32_t len);
int strcmp(char *str1, char *str2);
char *strcpy(char *dest, const char *src);
char *strcat(char *dest, const char *src);

#endif // COMMON_H
