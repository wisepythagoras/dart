#include "../include/string.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *
 *        Copy len bytes from src to dest.       *
 * * * * * * * * * * * * * * * * * * * * * * * * */
void memcpy(UINT8 *dest, const UINT8 *src, UINT32 len)
{
    const UINT8 *sp = (const UINT8 *)src;
    UINT8 *dp = (UINT8 *)dest;
    for(; len != 0; len--) *dp++ = *sp++;
}

