#ifndef KSTDIO_H
#define KSTDIO_H

#define GCC 

#if defined(GCC)
#define INLINE inline
#elif defined (MSVC)
#define INLINE __inline
#else

#define INLINE 
#endif

#include "def.h"
#include "comfunc.h"

void kput (char);
void kclear (void);
void kprintf (char *);

#endif
