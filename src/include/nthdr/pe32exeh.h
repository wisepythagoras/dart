#ifndef PE32EXEH_H
#define PE32EXEH_H

#include "../def.h"
#include "../global/global.h"

typedef struct 
{
    uint32_t    signature;
    uint16_t    cputype;
    uint16_t    objcnt;
 
    uint32_t    tdstamp;
    uint32_t    reserved1;
 
    uint32_t    reserved2;
    uint16_t    nthdrsize;
    uint16_t    flags;
 
    uint16_t    reserved3;
    uint16_t    lmajor;
    uint16_t    lminor;
    uint16_t    reserved4;
 
    uint32_t    reserved5;
    uint32_t    reserved6;
 
    uint32_t    entrypointrva;
    uint32_t    reserved7;
 
    uint32_t    reserved8;
    uint32_t    imagebase;
 
    uint32_t    objectalign;
    uint32_t    filealign;
 
    uint16_t    osmajor;
    uint16_t    osminor;
    uint16_t    usermajor;
    uint16_t    userminor;
 
    uint16_t    subsysmajor;
    uint16_t    subsysminor;
    uint32_t    reserved9;
 
    uint32_t    imagesize;
    uint32_t    hdrsize;
 
    uint32_t    filechecksum;
    uint16_t    subsystem;
    uint16_t    dllflags;
 
    uint32_t    stackreservesize;
    uint32_t    stackcommitsize;
 
    uint32_t    heapreservesize;
    uint32_t    heapcommitsize;
 
    uint32_t    reserved10;
    uint32_t    _rvasizes;
 
    struct
    {
        uint32_t    rva;
        uint32_t    size;
    } tables[];
 
} win32_pe32_fhdr;
 
#define WIN32_PE32_TABLE_EXPORT     0x00
#define WIN32_PE32_TABLE_IMPORT     0x01
#define WIN32_PE32_TABLE_RESOURCE   0x02
#define WIN32_PE32_TABLE_EXCEPTION  0x03
#define WIN32_PE32_TABLE_SECURITY   0x04
#define WIN32_PE32_TABLE_FIXUP      0x05
#define WIN32_PE32_TABLE_DEBUG      0x06
#define WIN32_PE32_TABLE_IMAGEDESC  0x07
#define WIN32_PE32_TABLE_MACHSPEC   0x08
#define WIN32_PE32_TABLE_THREADLOC  0x09
#define WIN32_PE32_TABLE_UNKNOWN1   0x0A
#define WIN32_PE32_TABLE_UNKNOWN2   0x0B
#define WIN32_PE32_TABLE_IMPORTADDR 0x0C
#define WIN32_PE32_TABLE_UNKNOWN3   0x0D
#define WIN32_PE32_TABLE_CLRRTHDR   0x0E

#endif