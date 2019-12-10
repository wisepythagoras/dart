#ifndef GLOBAL_H
#define GLOBAL_H

#include "../def.h"
#include "../comfunc.h"

#define ROUNDUP(a, b) (((a) + ((b)-1)) & ~((b)-1))
#define ROUNDOWN(a, b) (((a) / (b)) * (b))

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

#define CHECK_BIT(a, b) ((a) & (1 << (b)))
#define SET_BIT(a, b) ((a) | (1 << (b)))
#define CLEAR_BIT(a, b) ((a) & (~(1 << (b))))

#define TOUCH(x) ((void)(x))

// Define the endians
#define LITTLE_ENDIAN 1234
#define BIG_ENDIAN    4321

// Define the kernel arguments
struct KRNL_ARGS
{
    unsigned int cons_line;
    unsigned int mem_size;
    char *str;
//  const boot_entry *bootdir;
    unsigned int bootdir_size;
    unsigned int kernel_seg0_base;
    unsigned int kernel_seg0_size;
    unsigned int kernel_seg1_base;
    unsigned int kernel_seg1_size;
    unsigned int phys_alloc_range_low;
    unsigned int phys_alloc_range_high;
    unsigned int virt_alloc_range_low;
    unsigned int virt_alloc_range_high;
    unsigned int stack_start;
    unsigned int stack_end;
    // architecture specific
};



#endif