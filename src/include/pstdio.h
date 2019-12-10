#ifndef FS_H
#define FS_H

#include <stdarg.h>
#include <kstdio.h>

// Width of stack == width of int 
#define STACKITEM   int

// Round up width of objects pushed on stack. The expression before the
// & ensures that we get 0 for objects of size 0. 
#define VA_SIZE(TYPE)                   \
    ((sizeof(TYPE) + sizeof(STACKITEM) - 1) \
        & ~(sizeof(STACKITEM) - 1))

// &(LASTARG) points to the LEFTMOST argument of the function call
// (before the ...) 

// Flags used in processing format string 
#define     PR_LJ   0x01    // left justify 
#define     PR_CA   0x02    // use A-F instead of a-f for hex 
#define     PR_SG   0x04    // signed numeric conversion (%d vs. %u) 
#define     PR_32   0x08    // long (32-bit) numeric conversion 
#define     PR_16   0x10    // short (16-bit) numeric conversion 
#define     PR_WS   0x20    // PR_SG set and num was < 0 
#define     PR_LZ   0x40    // pad left with '0' instead of ' ' 
#define     PR_FP   0x80    // pointers are far 

// largest number handled is 2^32-1, lowest radix handled is 8.
// 2^32-1 in base 8 has 11 digits (add 5 for trailing NUL and for slop) 
#define     PR_BUFLEN   16

typedef int (*fnptr_t)(unsigned c, void **helper);

int printf(const char *fmt, ...);
void pclear();
void kputs(char c);

#endif
