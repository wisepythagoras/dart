// Out port B function
#include <comfunc.h>
#include <def.h>

void outb(uint16_t port, uint8_t value) {
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (port), "a" (value));
}

