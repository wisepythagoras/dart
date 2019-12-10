// In port W function
#include <comfunc.h>
#include <def.h>

uint16_t inpw(uint16_t port) {
    uint16_t ret;
    __asm__ __volatile__ ("inw %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}
