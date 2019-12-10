// stdlib function for pegasus os
#ifndef STDLIB_H_
#define STDLIB_H_

#include "inttypes.h"

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

typedef int32_t ssize_t;
typedef uint32_t size_t;

int atoi(const char *str);
long atol(const char *str);

void itoa(int val, char *buf, int base);
void utoa(int val, char *buf, int base);

/* defined in malloc.c */
void *malloc(size_t sz);
void free(void *ptr);

typedef struct {
    int quot;
    int rem;
} div_t;

typedef struct {
    long quot;
    long rem;
} ldiv_t;

#endif
