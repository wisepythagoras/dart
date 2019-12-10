#include <kstdio.h>
#include <def.h>
#include <comfunc.h>

// The VGA framebuffer starts at 0xB8000.

#define SERIAL_BASE 0x16000000
#define SERIAL_FLAG_REGISTER 0x18
#define SERIAL_BUFFER_FULL (1 << 5)

void kput(char c) {
    // Wait until the serial buffer is empty
    while (*(volatile unsigned long*)(SERIAL_BASE + SERIAL_FLAG_REGISTER) 
                                       & (SERIAL_BUFFER_FULL));
    // Put our character, c, into the serial buffer
    *(volatile unsigned long*)SERIAL_BASE = c;
}

void kprintf(char * str) {
    while (*str) kput(*str++);
}

void kclear() {

}
