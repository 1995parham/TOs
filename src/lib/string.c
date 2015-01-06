/*
 * In The Name Of God
 * ========================================
 * [] File Name : string.c
 *
 * [] Creation Date : 06-01-2015
 *
 * [] Last Modified : Tue 06 Jan 2015 08:49:23 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/

#include <string.h>

size_t strnlen(const char *s, size_t maxlen)
{
	const char *ns = s;
	while (*ns && maxlen) {
		ns++;
		maxlen--;
	}
	return (ns - s);
}
