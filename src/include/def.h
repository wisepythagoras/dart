#ifndef DEF_H
#define DEF_H

// In def.h we define all kinds of variables and
// integer types that we will want to use in other
// parts of the Kernel code just for our own work's
// sake (and for the sake time, not easy to write 
// "unsigned long long int var" every time).

// Correct magic number that should be passed
// to the kernel once booted off GRUB.
#define MAGICS          0x2BADB002

#define UINT8_AT(x)         (*((uint8_t*)(x)))
#define UINT16_AT(x)        (*((uint16_t*)(x)))
#define UINT32_AT(x)        (*((uint32_t*)(x)))

// Integer limits
#define INT8_MIN        -0x80
#define INT8_MAX        0x7F
#define UINT8_MAX       0xFF

#define INT16_MIN       -0x8000
#define INT16_MAX       0x7FFF
#define UINT16_MAX      0xFFFF

#define INT32_MIN       -0x80000000
#define INT32_MAX       0x7FFFFFFF
#define UINT32_MAX      0xFFFFFFFF

#define INT64_MIN       -0x8000000000000000LL
#define INT64_MAX       0x7FFFFFFFFFFFFFFFLL
#define UINT64_MAX      0xFFFFFFFFFFFFFFFFULL

#define INT_LEAST8_MIN      INT8_MIN
#define INT_LEAST8_MAX      INT8_MAX
#define UINT_LEAST8_MAX     UINT8_MAX

#define INT_LEAST16_MIN     INT16_MIN
#define INT_LEAST16_MAX     INT16_MAX
#define UINT_LEAST16_MAX    UINT16_MAX

#define INT_LEAST32_MIN     INT32_MIN
#define INT_LEAST32_MAX     INT32_MAX
#define UINT_LEAST32_MAX    UINT32_MAX

#define INT_LEAST64_MIN     INT64_MIN
#define INT_LEAST64_MAX     INT64_MAX
#define UINT_LEAST64_MAX    UINT64_MAX

#define INT_FAST8_MIN       INT32_MIN
#define INT_FAST8_MAX       INT32_MAX
#define UINT_FAST8_MAX      UINT32_MAX

#define INT_FAST16_MIN      INT32_MIN
#define INT_FAST16_MAX      INT32_MAX
#define UINT_FAST16_MAX     UINT32_MAX

#define INT_FAST32_MIN      INT32_MIN
#define INT_FAST32_MAX      INT32_MAX
#define UINT_FAST32_MAX     UINT32_MAX

#define INT_FAST64_MIN      INT64_MIN
#define INT_FAST64_MAX      INT64_MAX
#define UINT_FAST64_MAX     UINT64_MAX

#define INTPTR_MIN      INT32_MIN
#define INTPTR_MAX      INT32_MAX
#define UINTPTR_MAX     UINT32_MAX

#define INTMAX_MIN      INT64_MIN
#define INTMAX_MAX      INT64_MAX
#define UINTMAX_MAX     UINT64_MAX

#define SIZE_MAX        UINT32_MAX

// Define some global variables
typedef void            VOID;
typedef unsigned int        UINT;
typedef unsigned char       UCHAR;
typedef          char       CHAR;
// --
typedef unsigned long       UINT64;
typedef          long       SINT64;
typedef unsigned int        UINT32;
typedef          int        SINT32;
typedef unsigned short      UINT16;
typedef          short      SINT16;
typedef unsigned char       UINT8;
typedef          char       SINT8;

// Define some other global variables
typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned int        uint32_t;
typedef unsigned long long int  uint64_t;
//typedef signed char       int8_t;   // Already defined in inttypes.h, dumb me...
typedef signed short        int16_t;
typedef signed int      int32_t;
typedef signed long long int    int64_t;

// Small size integers
typedef uint32_t        uint_least8_t;
typedef uint32_t        uint_least16_t;
typedef uint32_t        uint_least32_t;
typedef uint64_t        uint_least64_t;
typedef int32_t         int_least8_t;
typedef int32_t         int_least16_t;
typedef int32_t         int_least32_t;
typedef int64_t         int_least64_t;

// Fast integers
typedef uint32_t        uint_fast8_t;
typedef uint32_t        uint_fast16_t;
typedef uint32_t        uint_fast32_t;
typedef uint64_t        uint_fast64_t;
typedef int32_t         int_fast8_t;
typedef int32_t         int_fast16_t;
typedef int32_t         int_fast32_t;
typedef int64_t         int_fast64_t;

// Pointer equivalent integers
typedef uint32_t        uintptr_t;
typedef int32_t         intptr_t;

// Largest sized integers
typedef uint64_t        uintmax_t;
typedef int64_t         intmax_t;

// Various sized integers
typedef uint32_t        size_t;

// System specific variables
typedef int             region_id;      // vm region id
typedef int             aspace_id;      // address space id
typedef int             thread_id;      // thread id
typedef int             proc_id;        // process id
typedef int             pgrp_id;        // process group id
typedef int             sess_id;        // session id
typedef int             sem_id;         // semaphore id
typedef int             port_id;        // ipc port id
typedef int             image_id;       // binary image id

typedef proc_id         pid_t;
typedef thread_id       tid_t;
typedef UINT32          mode_t;
typedef UINT32          nlink_t;
typedef UINT32          uid_t;
typedef UINT32          gid_t;
typedef UINT64          blkcnt_t;
typedef size_t          blksize_t;

#endif
