#include <zstack/lld/f28335/f28335.h>

struct f28335_timer {
	uint16_t counter_low;
	uint16_t counter_high;
	uint16_t reload_low;
	uint16_t reload_high;
	struct {
		uint16_t rsvd1 : 4;
		uint16_t disable : 1;
		uint16_t reload : 1;
		uint16_t rsvd2 : 4;
		uint16_t free_soft : 2;
		uint16_t rsvd3 : 2;
		uint16_t int_enable : 1;
		uint16_t int_flag : 1;
	} ctrl;
	uint16_t rsvd;
	struct {
		uint16_t prescale_reload : 8;
		uint16_t prescale_counter : 8;
	} prescale_low;
	struct {
		uint16_t prescale_reload : 8;
		uint16_t prescale_counter : 8;
	} prescale_high;
};

void f28335_timer_freqence_set(uint32_t base, uint32_t sysclkout, uint32_t freq)
{
	struct f28335_timer *timer = (void *)base;

	timer->reload_low = 1000000 & 0xFFFF;
	timer->reload_high = 1000000 >> 16;

	timer->prescale_low.prescale_reload = 100;
	timer->prescale_high.prescale_reload = 0;

	timer->ctrl.reload = 1;
	timer->ctrl.int_enable = 1;
}

void f28335_timer_disable(uint32_t base)
{
	struct f28335_timer *timer = (void *)base;

	timer->ctrl.disable = 1;
}

void f28335_timer_enable(uint32_t base)
{
	struct f28335_timer *timer = (void *)base;

	timer->ctrl.disable = 0;
}
