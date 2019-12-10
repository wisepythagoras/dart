#ifndef COMFUNC_H
#define COMFUNC_H

#include <def.h>

void     outb(uint16_t port, uint8_t value);
uint8_t  inpb(uint16_t port);
uint16_t inpw(uint16_t port);

#endif
