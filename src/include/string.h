/*
 * In The Name Of God
 * ========================================
 * [] File Name : string.h
 *
 * [] Creation Date : 06-01-2015
 *
 * [] Last Modified : Sat 31 Jan 2015 01:14:47 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef STRING_H
#define STRING_H

#ifndef NULL
#define NULL ((void *) 0)
#endif

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned int size_t;
#endif

extern char *strerror(int errno);

/*
 * This string-include defines all string functions as inline
 * functions. Use gcc. It also assumes ds=es=data space, this should be
 * normal. Most of the string-functions are rather heavily hand-optimized,
 * see especially strtok,strstr,str[c]spn. They should work, but are not
 * very easy to understand. Everything is done entirely within the register
 * set, making the functions fast and clean. String instructions have been
 * used through-out, making for "slightly" unclear code :-)
 *
 *		(C) 1991 Linus Torvalds
*/

/*
 * [] R General register (EAX, EBX, ECX, EDX, ESI, EDI, EBP, ESP)
 * [] q General register for data (EAX, EBX, ECX, EDX)
 * [] f Floating-point register
 * [] t Top floating-point register
 * [] u Second-from-top floating-point register
 * [] a EAX register
 * [] b EBX register
 * [] c ECX register
 * [] d EDX register
 * [] x SSE register (Streaming SIMD Extension register)
 * [] y MMX multimedia registers
 * [] A An 8-byte value formed from EAX and EDX
 * [] D Destination pointer for string operations (EDI)
 * [] S Source pointer for string operations (ESI)
 * [] m A memory operand is allowed, with any kind of address
 * that the machine supports in general.
 * [] o A memory operand is allowed, but only if the address is offsettable.
 * ie, adding a small offset to the address gives a valid address.
 * [] V A memory operand that is not offsettable.
 * In other words, anything that would fit the `m’ constraint but not the `o’constraint.
 * [] i An immediate integer operand (one with constant value) is allowed.
 * This includes symbolic constants whose values will be known only at assembly time.
 * [] n An immediate integer operand with a known numeric value is allowed.
 * Many systems cannot support assembly-time constants for operands less than a word wide.
 * Constraints for these operands should use ’n’ rather than ’i’.
 * [] g Any register, memory or immediate integer operand is allowed,
 * except for registers that are not general registers.
*/

/*
 *  asm ( assembler template
 *	: output operands                  * optional *
 *	: input operands                   * optional *
 *	: list of clobbered registers      * optional *
 *	);
 * There are two %’s prefixed to the register name.
 * This helps GCC to distinguish between the operands and registers.
 * operands have a single % as prefix.
 * The clobbered register %eax after the third colon tells GCC that
 * the value of %eax is to be modified inside "asm", so GCC won’t use
 * this register to store any other value.
*/

/*
 * NASM:
 *	cld
 *	mov si, src
 *	mov di, dest
 * .loop:
 *	lodsb
 *	stosb
 *	test al, al
 *	jnz .loop
*/
extern inline char *strcpy(char *dest, const char *src)
{
	__asm__("cld\n"
		"1:\tlodsb\n\t"
		"stosb\n\t"
		"testb %%al,%%al\n\t"
		"jne 1b"
		: /* no output registers */
		: "S" (src), "D" (dest)
		: "%al"
		);
	return dest;
}

/*
 * NASM:
 *	cld
 *	mov si, src
 *	mov di, dest
 *	mov cx, count
 * .loop:
 *	dec cx
 *	js .end
 *	lodsb
 *	stosb
 *	test al, al
 *	jne .loop
 *	rep stosb
 * .end:
*/
static inline char *strncpy(char *dest, const char *src, int count)
{
	__asm__("cld\n"
		"1:\tdecl %2\n\t"
		"js 2f\n\t"
		"lodsb\n\t"
		"stosb\n\t"
		"testb %%al,%%al\n\t"
		"jne 1b\n\t"
		"rep\n\t"
		"stosb\n"
		"2:"
		:
		: "S" (src), "D" (dest), "c" (count)
		: "%al"
		);
	return dest;
}

/*
 * NASM:
 *	cld
 *	mov si, src
 *	mov di, dest
 *	mov ax, 0
 *	mov cx, 0xffffffff
 *	repne scasb
 *	dec di
 * .loop:
 *	lodsb
 *	stosb
 *	test al, al
 *	jne .loop
*/
extern inline char *strcat(char *dest, const char *src)
{
	__asm__("cld\n\t"
		"repne\n\t"
		"scasb\n\t"
		"decl %1\n"
		"1:\tlodsb\n\t"
		"stosb\n\t"
		"testb %%al,%%al\n\t"
		"jne 1b"
		:
		: "S" (src), "D" (dest), "a" (0), "c" (0xffffffff)
		);
	return dest;
}

/*
 * NASM:
 *	cld
 *	mov si, src
 *	mov di, dest
 *	mov ax, 0
 *	mov cx, 0xffffffff
 *	mov ?, count	; What ever gcc want !!!
 *	repne scasb
 *	dec di
 *	mov cx, ?
 * .loop:
 *	dec cx
 *	js .end
 *	lodsb
 *	stosb
 *	test al, al
 *	jne .loop
 * .end:
 *	xor ax, ax
 *	stosb
*/
static inline char *strncat(char *dest, const char *src, int count)
{
	__asm__("cld\n\t"
		"repne\n\t"
		"scasb\n\t"
		"decl %1\n\t"
		"movl %4,%3\n"
		"1:\tdecl %3\n\t"
		"js 2f\n\t"
		"lodsb\n\t"
		"stosb\n\t"
		"testb %%al,%%al\n\t"
		"jne 1b\n"
		"2:\txorl %2,%2\n\t"
		"stosb"
		:
		: "S" (src), "D" (dest), "a" (0), "c" (0xffffffff), "g" (count)
		);
	return dest;
}

/*
 * NASM:
 *	cld
 *	mov di, cs
 *	mov si, ct
 * .loop:
 *	lodsb
 *	scasb
 *	jne .not_equal
 *	test al, al
 *	jne .loop
 *	xor al, al
 *	jmp .end
 * .not_equal:
 *	mov ax, di
 *	jl .end
 *	neg ax
 * .end:
 *	mov __res, al
*/
extern inline int strcmp(const char *cs, const char *ct)
{
	register int __res ;
	__asm__("cld\n"
		"1:\tlodsb\n\t"
		"scasb\n\t"
		"jne 2f\n\t"
		"testb %%al,%%al\n\t"
		"jne 1b\n\t"
		"xorl %%eax,%%eax\n\t"
		"jmp 3f\n"
		"2:\tmovl $1,%%eax\n\t"
		"jl 3f\n\t"
		"negl %%eax\n"
		"3:"
		: "=a" (__res)
		: "D" (cs), "S" (ct)
		);
	return __res;
}

/*
 * NASM:
 *	cld
 *	mov di, cs
 *	mov si, ct
 *	mov cx, count
*/
static inline int strncmp(const char *cs, const char *ct, int count)
{
	register int __res ;
	__asm__("cld\n"
		"1:\tdecl %3\n\t"
		"js 2f\n\t"
		"lodsb\n\t"
		"scasb\n\t"
		"jne 3f\n\t"
		"testb %%al,%%al\n\t"
		"jne 1b\n"
		"2:\txorl %%eax,%%eax\n\t"
		"jmp 4f\n"
		"3:\tmovl $1,%%eax\n\t"
		"jl 4f\n\t"
		"negl %%eax\n"
		"4:"
		: "=a" (__res)
		: "D" (cs), "S" (ct), "c" (count)
		);
	return __res;
}

static inline char *strchr(const char *s, char c)
{
register char *__res ;
__asm__("cld\n\t"
	"movb %%al,%%ah\n"
	"1:\tlodsb\n\t"
	"cmpb %%ah,%%al\n\t"
	"je 2f\n\t"
	"testb %%al,%%al\n\t"
	"jne 1b\n\t"
	"movl $1,%1\n"
	"2:\tmovl %1,%0\n\t"
	"decl %0"
	:"=a" (__res):"S" (s),"0" (c));
return __res;
}

static inline char *strrchr(const char *s, char c)
{
register char *__res;
__asm__("cld\n\t"
	"movb %%al,%%ah\n"
	"1:\tlodsb\n\t"
	"cmpb %%ah,%%al\n\t"
	"jne 2f\n\t"
	"movl %%esi,%0\n\t"
	"decl %0\n"
	"2:\ttestb %%al,%%al\n\t"
	"jne 1b"
	:"=d" (__res):"0" (0),"S" (s),"a" (c));
return __res;
}

extern inline int strspn(const char *cs, const char *ct)
{
register char *__res;
__asm__("cld\n\t"
	"movl %4,%%edi\n\t"
	"repne\n\t"
	"scasb\n\t"
	"notl %%ecx\n\t"
	"decl %%ecx\n\t"
	"movl %%ecx,%%edx\n"
	"1:\tlodsb\n\t"
	"testb %%al,%%al\n\t"
	"je 2f\n\t"
	"movl %4,%%edi\n\t"
	"movl %%edx,%%ecx\n\t"
	"repne\n\t"
	"scasb\n\t"
	"je 1b\n"
	"2:\tdecl %0"
	:"=S" (__res):"a" (0),"c" (0xffffffff),"0" (cs),"g" (ct)
	);
return __res-cs;
}

extern inline int strcspn(const char *cs, const char *ct)
{
register char * __res;
__asm__("cld\n\t"
	"movl %4,%%edi\n\t"
	"repne\n\t"
	"scasb\n\t"
	"notl %%ecx\n\t"
	"decl %%ecx\n\t"
	"movl %%ecx,%%edx\n"
	"1:\tlodsb\n\t"
	"testb %%al,%%al\n\t"
	"je 2f\n\t"
	"movl %4,%%edi\n\t"
	"movl %%edx,%%ecx\n\t"
	"repne\n\t"
	"scasb\n\t"
	"jne 1b\n"
	"2:\tdecl %0"
	:"=S" (__res):"a" (0),"c" (0xffffffff),"0" (cs),"g" (ct)
	);
return __res-cs;
}

extern inline char *strpbrk(const char *cs, const char *ct)
{
register char *__res ;
__asm__("cld\n\t"
	"movl %4,%%edi\n\t"
	"repne\n\t"
	"scasb\n\t"
	"notl %%ecx\n\t"
	"decl %%ecx\n\t"
	"movl %%ecx,%%edx\n"
	"1:\tlodsb\n\t"
	"testb %%al,%%al\n\t"
	"je 2f\n\t"
	"movl %4,%%edi\n\t"
	"movl %%edx,%%ecx\n\t"
	"repne\n\t"
	"scasb\n\t"
	"jne 1b\n\t"
	"decl %0\n\t"
	"jmp 3f\n"
	"2:\txorl %0,%0\n"
	"3:"
	:"=S" (__res):"a" (0),"c" (0xffffffff),"0" (cs),"g" (ct)
	);
return __res;
}

extern inline char *strstr(const char *cs, const char *ct)
{
register char *__res ;
__asm__("cld\n\t" \
	"movl %4,%%edi\n\t"
	"repne\n\t"
	"scasb\n\t"
	"notl %%ecx\n\t"
	"decl %%ecx\n\t"	/* NOTE! This also sets Z if searchstring='' */
	"movl %%ecx,%%edx\n"
	"1:\tmovl %4,%%edi\n\t"
	"movl %%esi,%%eax\n\t"
	"movl %%edx,%%ecx\n\t"
	"repe\n\t"
	"cmpsb\n\t"
	"je 2f\n\t"		/* also works for empty string, see above */
	"xchgl %%eax,%%esi\n\t"
	"incl %%esi\n\t"
	"cmpb $0,-1(%%eax)\n\t"
	"jne 1b\n\t"
	"xorl %%eax,%%eax\n\t"
	"2:"
	:"=a" (__res):"0" (0),"c" (0xffffffff),"S" (cs),"g" (ct)
	);
return __res;
}

/*
 * NASM:
 *	cld
 *	mov di, s
 *	mov ax, 0
 *	mov cx, 0xffffffff
 *	repne scasb
 *	not cx
 *	dec cx
 *	mov __res, cx
*/
extern inline size_t strlen(const char *s)
{
	register int __res ;

	__asm__("cld\n\t"
		"repne\n\t"
		"scasb\n\t"
		"notl %0\n\t"
		"decl %0"
		: "=c" (__res)
		: "D" (s), "a" (0), "0" (0xffffffff)
		);
	return __res;
}

/*
 * NASM:
 *	cld
 *	mov di, s
 *	mov ax, 0
 *	mov cx, maxlen
 *	repne scasb
 *	neg cx
 *	add cx, maxlen
 *	mov __res, cx
*/
static inline size_t strnlen(const char *s, size_t maxlen)
{
	register int __res;

	__asm__("cld\n\t"
		"repne\n\t"
		"scasb\n\t"
		"negl %0\n\t"
		"addl %4,%0"
		: "=c" (__res)
		: "D" (s), "a" (0), "0" (maxlen), "m" (maxlen)
		);
	return __res;
}

extern char *___strtok;

extern inline char *strtok(char *s, const char *ct)
{
	register char *__res;
	
	__asm__("testl %1,%1\n\t"
		"jne 1f\n\t"
		"testl %0,%0\n\t"
		"je 8f\n\t"
		"movl %0,%1\n"
		"1:\txorl %0,%0\n\t"
		"movl $-1,%%ecx\n\t"
		"xorl %%eax,%%eax\n\t"
		"cld\n\t"
		"movl %4,%%edi\n\t"
		"repne\n\t"
		"scasb\n\t"
		"notl %%ecx\n\t"
		"decl %%ecx\n\t"
		"je 7f\n\t"			/* empty delimeter-string */
		"movl %%ecx,%%edx\n"
		"2:\tlodsb\n\t"
		"testb %%al,%%al\n\t"
		"je 7f\n\t"
		"movl %4,%%edi\n\t"
		"movl %%edx,%%ecx\n\t"
		"repne\n\t"
		"scasb\n\t"
		"je 2b\n\t"
		"decl %1\n\t"
		"cmpb $0,(%1)\n\t"
		"je 7f\n\t"
		"movl %1,%0\n"
		"3:\tlodsb\n\t"
		"testb %%al,%%al\n\t"
		"je 5f\n\t"
		"movl %4,%%edi\n\t"
		"movl %%edx,%%ecx\n\t"
		"repne\n\t"
		"scasb\n\t"
		"jne 3b\n\t"
		"decl %1\n\t"
		"cmpb $0,(%1)\n\t"
		"je 5f\n\t"
		"movb $0,(%1)\n\t"
		"incl %1\n\t"
		"jmp 6f\n"
		"5:\txorl %1,%1\n"
		"6:\tcmpb $0,(%0)\n\t"
		"jne 7f\n\t"
		"xorl %0,%0\n"
		"7:\ttestl %0,%0\n\t"
		"jne 8f\n\t"
		"movl %0,%1\n"
		"8:"
		: "=b" (__res), "=S" (___strtok)
		: "0" (___strtok), "1" (s), "g" (ct)
		);
	return __res;
}

/*
 * Changes by falcon<zhangjinw@gmail.com>, the original return value is static
 * inline ... it can not be called by other functions in another files.
*/

extern inline void *memcpy(void *dest, const void *src, int n)
{
	__asm__ ("cld\n\t"
		"rep\n\t"
		"movsb"
		:
		:"c" (n),"S" (src),"D" (dest)
		);
	return dest;
}

extern inline void *memmove(void *dest, const void *src, int n)
{
	if (dest < src)
		__asm__("cld\n\t"
			"rep\n\t"
			"movsb"
			:
			:"c" (n),"S" (src),"D" (dest)
			);
	else
		__asm__("std\n\t"
		"rep\n\t"
		"movsb"
		:
		:"c" (n),"S" (src+n-1),"D" (dest+n-1)
		);
	return dest;
}

static inline int memcmp(const void *cs, const void *ct, int count)
{
	register int __res ;
	__asm__("cld\n\t"
		"repe\n\t"
		"cmpsb\n\t"
		"je 1f\n\t"
		"movl $1,%%eax\n\t"
		"jl 1f\n\t"
		"negl %%eax\n"
		"1:"
		:"=a" (__res):"0" (0),"D" (cs),"S" (ct),"c" (count)
		);
	return __res;
}

extern inline void *memchr(const void *cs, char c, int count)
{
	register void *__res ;
	if (!count)
		return NULL;
	__asm__("cld\n\t"
		"repne\n\t"
		"scasb\n\t"
		"je 1f\n\t"
		"movl $1,%0\n"
		"1:\tdecl %0"
		:"=D" (__res):"a" (c),"D" (cs),"c" (count)
		);
	return __res;
}

/*
 * NASM:
 *	cld
 *	mov ax, c
 *	mov si, s
 *	mov cx, count
 *	rep stosb
*/
static inline void *memset(void *s, char c, int count)
{
	__asm__("cld\n\t"
		"rep\n\t"
		"stosb"
		:
		: "a" (c),"D" (s),"c" (count)
		);
	return s;
}

#endif
