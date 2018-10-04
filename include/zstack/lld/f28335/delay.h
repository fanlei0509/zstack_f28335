#ifndef DELAY_H
#define DELAY_H

#include <zstack/libc/stdint.h>

static inline void f28335_delay_us(uint32_t sysclkout, uint32_t us)
{
	volatile uint32_t cycle;

	for (cycle = 0; cycle < sysclkout; cycle++);
}

#endif
