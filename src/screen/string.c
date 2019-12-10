// string function for pegasus os
#include "../include/string.h"

void memset16(void *s, int c, size_t n)
{
    short *ptr = s;
    while(n--) 
    {
        *ptr++ = c;
    }
}

void *memmove(void *dest, const void *src, size_t n)
{
    int i;
    char *dptr;
    const char *sptr;

    if(dest <= src) 
    {
        // forward copy 
        dptr = dest;
        sptr = src;
        for(i=0; i<n; i++) {
            *dptr++ = *sptr++;
        }
    } else {
        // backwards copy 
        dptr = dest + n - 1;
        sptr = src + n - 1;
        for(i=0; i<n; i++) {
            *dptr-- = *sptr--;
        }
    }

    return dest;
}

char *strchr(const char *s, int c)
{
    while(*s) 
    {
        if(*s == c) 
        {
            return (char*)s;
        }
        s++;
    }
    return 0;
}

char *strrchr(const char *s, int c)
{
    const char *ptr = s;

    // find the end 
    while(*ptr) ptr++;

    // go back checking for c 
    while(--ptr >= s) 
    {
        if(*ptr == c) 
        {
            return (char*)ptr;
        }
    }
    return 0;
}
