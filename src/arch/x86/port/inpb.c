// In port B function
#include <comfunc.h>
#include <def.h>

uint8_t  inpb(uint16_t port) {
    uint8_t ret;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}
