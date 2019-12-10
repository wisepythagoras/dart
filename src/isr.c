#include <def.h>
#include <stdio.h>
#include <global/isr.h>
#include <global/global.h>

isr_t interrupt_handlers[256];

void register_interrupt_handler(uint8_t n, isr_t handler) {
    interrupt_handlers[n] = handler;
}

void isr_handler(registers_t regs) {
    printf("[Recieved interrupt: %i]\n", regs.int_no);
}

// This gets called from our ASM interrupt handler stub.
void irq_handler(registers_t regs) {
    // Send an EOI (end of interrupt) signal to the PICs.
    // If this interrupt involved the slave.
    if (regs.int_no >= 40) {
        // Send reset signal to slave.
        outb(0xA0, 0x20);
    }

    // Send reset signal to master. (As well as slave, if necessary).
    outb(0x20, 0x20);

    if (interrupt_handlers[regs.int_no] != 0) {
        isr_t handler = interrupt_handlers[regs.int_no];
        handler(regs);
    }
    else printf("No handler\n");
}

/*void irq_handler(registers_t regs) {
    // Send an EOI (end of interrupt) signal to the PICs.
    // If this interrupt involved the slave.

    // This is a blank function pointer
    void (*handler)(registers_t regs);

    // Find out if we have a custom handler to run for this
    // IRQ, and then finally, run it
    handler = interrupt_handlers[regs.int_no - 32];

    // Call the handler.
    if(handler) handler(regs);

    // If the IDT entry that was invoked was greater than 40
    //  (meaning IRQ8 - 15), then we need to send an EOI to
    //  the slave controller
    if(regs.int_no >= 40) outb(0xA0, 0x20);

    // In either case, we need to send an EOI to the master
    //  interrupt controller too
    outb(0x20, 0x20);
}*/

