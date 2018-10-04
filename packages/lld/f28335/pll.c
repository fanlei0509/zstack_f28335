#include <zstack/lld/f28335/f28335.h>

struct pll {
	volatile uint16_t pllsts;
	volatile uint16_t rsvd1[8];
	volatile uint16_t hispcp;
	volatile uint16_t lospcp;
	volatile uint16_t pclkcr0;
	volatile uint16_t pclkcr1;
	volatile uint16_t lpmcr0;
	volatile uint16_t rsvd2;
	volatile struct {
		uint16_t rsvd0 : 8;
		uint16_t cpu_timer_0 : 1;
		uint16_t cpu_timer_1 : 1;
		uint16_t cpu_timer_2 : 1;
		uint16_t dma : 1;
		uint16_t xintf : 1;
		uint16_t gpio : 1;
		uint16_t rsvd1 : 2;
	} pclkcr3;
	volatile uint16_t pllcr;
};

#define Pf28335_DIV_4_DEFAULT	(0)

#define CLOCK_GPIO	BIT(13)

BOOL f28335_pll_limp_mode_detect(uint32_t base)
{
	struct pll *pll = (void *)base;

	return pll->pllsts & BIT(3) ? TRUE : FALSE;
}

void f28335_pll_cpu_freq_set(uint32_t base, uint32_t oscclk, uint32_t freq)
{
	struct pll *pll = (void *)base;

	uint16_t div;
	uint16_t mul;

	ASSERT(freq <= SYSCLKOUT_MAX);

	mul = freq / oscclk;

	div = BITS_GET(pll->pllsts, 8, 7);

	// change PLL to default mode
	if (div != Pf28335_DIV_4_DEFAULT) {
		BITS_SET_SAFE(pll->pllsts, 8, 7, Pf28335_DIV_4_DEFAULT);
	}

	// disable oscillator detect logic
	BITS_SET_SAFE(pll->pllsts, 6, 6, 1);

	BITS_SET_SAFE(pll->pllcr, 3, 0, mul);

	// wait for PLL lock the frequency
	while (FALSE == BITS_GET(pll->pllsts, 0, 0));

	// enable oscillator detect logic
	BITS_SET_SAFE(pll->pllsts, 6, 6, 0);

	// If switching to 1/1
	// First go to 1/2 and let the power settle
	if (3 == div) {
		BITS_SET_SAFE(pll->pllsts, 8, 7, 2);
		f28335_delay_us(oscclk, 50);
	}

	// resume PLLSTS.div
	BITS_SET_SAFE(pll->pllsts, 8, 7, div);
}

uint32_t f28335_pll_cpu_freq_get(uint32_t base, uint32_t oscclk)
{
	struct pll *pll = (void *)base;

	uint16_t div;
	uint16_t mul;

	uint32_t sysclkout;

	div = BITS_GET(pll->pllsts, 8, 7);
	mul = BITS_GET(pll->pllcr, 3, 0);

	if (mul == 0)
		mul = 1;

	sysclkout = oscclk * mul;

	if (3 == div)
		return sysclkout;
	else if (2 == div)
		return sysclkout / 2;
	else
		return sysclkout / 4;
}

void f28335_pll_high_peripheral_freq_set(uint32_t base, uint32_t freq)
{
	struct pll *pll = (void *)base;

	pll->hispcp = 1;
}

void f28335_pll_low_peripheral_freq_set(uint32_t base, uint32_t freq)
{
	struct pll *pll = (void *)base;

	pll->lospcp = 2;
}

void f28335_pll_peripheral_enable(uint32_t base, enum f28335_ip ip)
{
	struct pll *pll = (void *)base;

	EALLOW;

	switch (ip) {
	case F28335_IP_GPIO:
		pll->pclkcr3.gpio = F28335_IP_CLOCK_ON;
		break;
	default:
		break;
	}

	EDIS;
}

void f28335_pll_peripheral_disable(uint32_t base, enum f28335_ip ip)
{

}
