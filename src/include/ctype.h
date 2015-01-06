/*
 * In The Name Of God
 * ========================================
 * [] File Name : ctype.h
 *
 * [] Creation Date : 06-01-2015
 *
 * [] Last Modified : Tue 06 Jan 2015 09:08:48 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef CTYPE_H
#define CTYPE_H

static inline int isdigit(int ch)
{
	return (ch >= '0') && (ch <= '9');
}

static inline int isxdigit(int ch)
{
	if (isdigit(ch))
		return 1;

	if ((ch >= 'a') && (ch <= 'f'))
		return 1;

	return (ch >= 'A') && (ch <= 'F');
}

#endif
