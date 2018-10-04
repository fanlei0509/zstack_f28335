#ifndef C2000_H
#define C2000_H

#include <zstack/libc/stdint.h>

#define EINT   asm(" clrc INTM")
#define DINT   asm(" setc INTM")
#define ERTM   asm(" clrc DBGM")
#define DRTM   asm(" setc DBGM")
#define EALLOW asm(" EALLOW")
#define EDIS   asm(" EDIS")
#define ESTOP0 asm(" ESTOP0")

extern cregister volatile unsigned int IFR;
extern cregister volatile unsigned int IER;

#define BITS_SET_SAFE(reg, b, a, v)	do {		\
	EALLOW;										\
	BITS_SET(reg, b, a, v);						\
	EDIS;										\
} while (0)

#endif
