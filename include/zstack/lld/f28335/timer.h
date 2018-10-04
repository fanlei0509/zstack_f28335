#ifndef F28335_TIMER_H
#define F28335_TIMER_H

extern void f28335_timer_enable(uint32_t base);
extern void f28335_timer_disable(uint32_t base);

extern void f28335_timer_freqence_set(uint32_t base, uint32_t sysclkout, uint32_t freq);

#endif
