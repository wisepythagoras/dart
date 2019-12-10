#include "../include/string.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *
 *      Write leng copies of val into dest.      *
 * * * * * * * * * * * * * * * * * * * * * * * * */
/*void memset(UINT8 *dest, UINT8 val, UINT32 len)
{
    UINT8 *temp = (UINT8 *)dest;
    for ( ; len != 0; len--) *temp++ = val;
}

void *memset(void *s, int c, size_t n)
{
    unsigned char* p=s;
    while(n--)
        *p++ = (unsigned char)c;
    return s;
}
*/

void *memset(void *dest, int val, size_t len) {
    unsigned char *temp = dest;
    for (; len != 0; len--) *temp++ = val;

    return temp;
}
