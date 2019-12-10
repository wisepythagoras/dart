#include <comfunc.h>
#include <def.h>
#include <kstdio.h>
#include <multiboot.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arch/cpuid.h>
#include <def.h>
#include <timer.h>
#include <comfunc.h>
#include <global/gdt.h>

// Defined in interrupts.s
extern void init_interrupts(void);
extern void test_interrupts(void);

// Kernel entry point
void _main(struct multiboot *mboot_ptr, uint32_t initial_stack) {
    // Clear screen to get rid of boot messages.
    kclear();

    // Initialise all the ISRs and segmentation.
    init_dt();

    // Some print tests.
    kprintf("Boot successfull\n");
    int num = 36;
    printf("Integer \"num\" = %i.\n", num);
    printf("Initial kernel stack is: %i\n", initial_stack);

    // Test the interrupts.
    printf("Testing interrupts\n");
    test_interrupts();

    // Initialize interrupts.
    printf("Initializing Interrupts\n");
    init_interrupts();

    printf("The kernel has booted\n");

    // Start the timer.
    init_timer(50);

    for(;;) { }
}

