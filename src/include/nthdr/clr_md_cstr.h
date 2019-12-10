#ifndef CLR_MD_CSTR_H
#define CLR_MD_CSTR_H

#include "../def.h"
#include "../global/global.h"

typedef struct {
/*
    The meta-data contains streams. There are:
    #~
    #GUID
    #US
    #Strings
 
    Each of these is stored in this structure.
*/
    uint8_t             *name;      /* ASCII name */
    uint8_t             *data;      /* if non-zero is buffer */
    uint32_t            size;       /* size in bytes */
} win_clr20_meta_stream;
 
typedef struct {
/*
    This structure holds the table once it has been
    read from the meta-data #~ stream. It holds the
    rows in a fixed static grid. You can get the size
    of each row (which is constant), and the size of
    each field in the row. However, there is no naming
    per field.
*/
    uint32_t            rowcnt;
    uint8_t             rsize;      /* row size in bytes */
    uint8_t             *fsize;     /* size of each field from left to right in bytes */
    uint8_t             *rows;      /* array of pointers to row data for each row */
} win_clr20_meta_table;
 
typedef struct {
/*
    This is the main structure for the meta-data. It
    should allow access to other information from this
    structure.
*/
    uint16_t            strmcnt;            /* the number of array items below */
    win_clr20_meta_stream       *strms;             /* an array just like they are read in */
    win_clr20_meta_stream       strmbyid[5];        /* copy of strms, but indexed by WIN_CLR20_META_ */
 
    uint8_t             heapoffsetsizes;    /* heap offset sizes */
    uint32_t            valid[2];           /* qword(64bit) tells which tables are present */
    uint32_t            sorted[2];          /* qword(64bit) tells which tables are sorted */
 
    win_clr20_meta_table            tables[64];         /* all the known tables that are supported */
} win_clr20_meta;
 
/*
    A quick bit guide to find the right one.
*/
#define CLR20_META_HEAPOFFSETSIZES_STRING       0x01
#define CLR20_META_HEAPOFFSETSIZES_GUID         0x02
#define CLR20_META_HEAPOFFSETSIZES_BLOB         0x03
 
/* 
    The identifier for each stream. This is
    specific to win_clr20_meta. These values
    are internal to this code.
*/
#define WIN_CLR20_META_TABLES       0x00
#define WIN_CLR20_META_USTRINGS     0x01
#define WIN_CLR20_META_STRINGS      0x02
#define WIN_CLR20_META_BLOB     0x03
#define WIN_CLR20_META_GUID     0x04
 
typedef struct 
{
    uintptr_t           rva;
    uintptr_t           size;
    uint8_t             *data;
} win_clr20_chunk;
 
typedef struct 
{
/*
    A container for the meta-data and
    for any other structures.
 
    Also included are the object sections
    like .text, .reloc, ect. These are kept
    because the meta data will reference
    into this sections. So we need to keep
    them close, but they are not actual 
    meta data so they are outside of the
    meta structure.
*/
    win_clr20_meta          meta;
 
    uint32_t            chunkcnt;
    win_clr20_chunk         *chunks;
} win_clr20_module;

#endif