#include <zstack/lld/f28335/f28335.h>

struct xintf {
	uint16_t XTIMING0;
};

#define XCLKOUT_PRESCALE_DEFAULT			(4)

void f28335_xintf_xclkout_freq_set(uint32_t base, uint32_t freq)
{
	struct xintf *xintf = (void *)base;

	(void)xintf;
}
