#ifndef F28335_PIE_H
#define F28335_PIE_H

enum f28335_pie_interrupt {
	F28335_PIE_INT_TIMER0 = 0 << 8 | 6
};

extern void f28335_pie_enable(uint32_t base);

extern void f28335_pie_interrupt_enable(uint32_t base, enum f28335_pie_interrupt intr);

extern void f28335_pie_ack(uint32_t base, enum f28335_pie_interrupt intr);

#endif
