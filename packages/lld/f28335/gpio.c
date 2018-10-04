#include <zstack/lld/f28335/f28335.h>

struct f28335_gpio_register {
	volatile uint32_t gpactrl;
	volatile uint32_t gpaqsel1;
	volatile uint32_t gpaqsel2;
	volatile uint32_t gpamux1;
	volatile uint32_t gpamux2;
	volatile uint32_t gpadir;
	volatile uint32_t gpapud;
	volatile uint16_t rsvd0[2];

	volatile uint32_t gpbctrl;
	volatile uint32_t gpbqsel1;
	volatile uint32_t gpbqsel2;
	volatile uint32_t gpbmux1;
	volatile uint32_t gpbmux2;
	volatile uint32_t gpbdir;
	volatile uint32_t gpbpud;
	volatile uint16_t rsvd1[8];

	volatile uint32_t gpcmux1;
	volatile uint32_t gpcmux2;
	volatile uint32_t gpcdir;
	volatile uint32_t gpcpud;
	volatile uint16_t rsvd2[18];

	volatile uint32_t gpadat;
	volatile uint32_t gpaset;
	volatile uint32_t gpaclear;
	volatile uint32_t gpatoggle;

	volatile uint32_t gpbdat;
	volatile uint32_t gpbset;
	volatile uint32_t gpbclear;
	volatile uint32_t gpbtoggle;

	volatile uint32_t gpcdat;
	volatile uint32_t gpcset;
	volatile uint32_t gpcclear;
	volatile uint32_t gpctoggle;
	volatile uint16_t rsvd3[8];

	volatile uint16_t gpioxint1sel;
	volatile uint16_t gpioxint2sel;
	volatile uint16_t gpioxnmisel;
	volatile uint16_t gpioxint3sel;
	volatile uint16_t gpioxint4sel;
	volatile uint16_t gpioxint5sel;
	volatile uint16_t gpioxint6sel;
	volatile uint16_t gpioint7sel;
	volatile uint32_t gpiolpmsel;
	volatile uint16_t rsvd4[22];
};

void f28335_gpio_func(uint32_t base, enum f28335_gpio io, enum f28335_gpio_func func)
{
	struct f28335_gpio_register *gpio = (void *)base;

	if (io <= F28335_GPIO_15) {
		BITS_SET_SAFE(gpio->gpamux1, io * 2 + 1, io * 2, func);
	}
}

void f28335_gpio_dir(uint32_t base, enum f28335_gpio io, enum f28335_gpio_dir dir)
{
	struct f28335_gpio_register *gpio = (void *)base;

	if (io <= F28335_GPIO_31) {
		BITS_SET_SAFE(gpio->gpadir, io, io, dir);
	}
}

void f28335_gpio_output(uint32_t base, enum f28335_gpio io, enum f28335_gpio_level lvl)
{
	struct f28335_gpio_register *gpio = (void *)base;

	if (io <= F28335_GPIO_31) {
		BITS_SET(gpio->gpadat, io, io, lvl);
	}
}
