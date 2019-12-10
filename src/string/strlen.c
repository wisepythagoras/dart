#include "../include/string.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *
 *     Return the length of a string (char*)     *
 * * * * * * * * * * * * * * * * * * * * * * * * */
int strlen(char *src)
{
    int i = 0;
    while (*src++)
        i++;
    return i;
}


