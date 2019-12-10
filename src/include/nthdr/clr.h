#ifndef CLR_H
#define CLR_H

#include "../def.h"
#include "../global/global.h"

typedef struct 
{
    uint32_t    rva;
    uint32_t    size;
} win32_clr20_datadir;
 
// http://ntcore.com/files/dotnetformat.htm 
typedef struct 
{
    uint32_t            cb;
    uint16_t            rtmajor;
    uint16_t            rtminor;
    win32_clr20_datadir     meta;
    uint32_t            flags;
    uint32_t            entrypointrva;  /* entry point rva */
    win32_clr20_datadir     resources;  /* resources */
    win32_clr20_datadir     strongnamsig;   /* strong name signature */
    win32_clr20_datadir     codemantab; /* code manager table */
    win32_clr20_datadir     vtabfixups; /* vtable fixups */
    win32_clr20_datadir     exaddrtabjumps; /* export address table jumps */
} win32_clr20_hdr;

#endif