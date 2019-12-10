// string function for pegasus os
#ifndef STRING_H
#define STRING_H

#include "stdlib.h"
#include "def.h"

void *memset(void *s, int c, size_t n);
void memset16(void *s, int c, size_t n);

///void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);

///size_t strlen(const char *s);

char *strchr(const char *s, int c);
char *strrchr(const char *s, int c);

// root/string/*.c
int strlen(char *src);
char *strcat(char *dest, const char *src);
int strcmp(char *str1, char *str2);
char *strcpy(char *dest, const char *src);
//void memset(UINT8 *dest, UINT8 val, UINT32 len);
void memcpy(UINT8 *dest, const UINT8 *src, UINT32 len);

#endif  // STRING_H
