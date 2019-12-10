// stdio function for pegasus os
#ifndef STDIO_H_
#define STDIO_H_

#include "stdlib.h"
#include "stdarg.h"

typedef int (*fnptr_t)(unsigned c, void **helper);

int putchar(int c);
int puts(const char *s);

int printf(const char *fmt, ...);
int vprintf(const char *fmt, va_list ap);
int do_printf(const char *fmt, va_list args, fnptr_t fn, void *ptr);

int sprintf(char *buf, const char *fmt, ...);
int vsprintf(char *buf, const char *fmt, va_list ap);

int snprintf(char *buf, size_t sz, const char *fmt, ...);
int vsnprintf(char *buf, size_t sz, const char *fmt, va_list ap);

#endif  /* STDIO_H_ */
