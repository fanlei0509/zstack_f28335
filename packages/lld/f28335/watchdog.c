/*
 * Reference
 *    [1] TMS320x2833x System Control and Interrupts.pdf
 */

#include <zstack/lld/f28335/f28335.h>

struct watchdog {
	volatile uint16_t scsr;
	volatile uint16_t wdcntr;
	volatile uint16_t rsvd1[1];
	volatile uint16_t wdkey;
	volatile uint16_t rsvd2[3];
	volatile uint16_t wdcr;
};

#define SCSR_WDINTS		BIT(2)
#define SCSR_WDENINT	BIT(1)
#define SCSR_WDOVERRIDE	BIT(0)	// TODO
#define WDCR_WDFLAG		BIT(7)
#define WDCR_WDDIS		BIT(6)
#define WDCR_WDCHK		BIT(3)

#define WDCR_DISABLE	BIT(6)
#define WDCR_CHECK		(0x5 << 3)
#define WDCR_PRESCALE	(0)

void f28335_watchdog_disable(uint32_t base)
{
	struct watchdog *wdt = (void *)base;

	EALLOW;
	wdt->wdcr = 0x0068;
	EDIS;
}

void f28335_watchdog_enable(uint32_t base)
{
	struct watchdog *wdt = (void *)base;

	EALLOW;
	wdt->wdcr = WDCR_PRESCALE | WDCR_CHECK;
	EDIS;
}

BOOL f28335_watchdog_reset(uint32_t base)
{
	struct watchdog *wdt = (void *)base;
	uint16_t value;

	EALLOW;
	value = wdt->wdcr;
	EDIS;

	return value ? TRUE : FALSE;
}
