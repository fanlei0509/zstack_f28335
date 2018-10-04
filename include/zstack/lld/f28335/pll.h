#ifndef LLD_F28335_H
#define LLD_F28335_H

enum f28335_clock {
	F28335_IP_CLOCK_ON = 1,
	F28335_IP_CLOCK_OFF = 0
};

enum f28335_ip {
	F28335_IP_CORE,
	F28335_IP_GPIO,
	F28335_IP_MAX
};

extern uint32_t f28335_pll_cpu_freq_get(uint32_t base, uint32_t oscclk);

extern void f28335_pll_peripheral_enable(uint32_t base, enum f28335_ip ip);

#endif
