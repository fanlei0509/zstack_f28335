#include <zstack/lld/f28335/f28335.h>

uint32_t cpu_timer_2_isr_counter = 0;

static interrupt void cpu_timer_2_isr(void)
{
	cpu_timer_2_isr_counter++;
}

int timer_2_interrupt(void)
{
	f28335_watchdog_disable(F28335_WATCHDOG_BASE);

	f28335_vector_table_init(F28335_PIE_VECTOR_BASE);
	f28335_vector_table_register(F28335_PIE_VECTOR_BASE, F28335_VECTOR_INT14, cpu_timer_2_isr);

	f28335_pll_cpu_freq_get(F28335_PLL_BASE, 30*1000*1000U);

	f28335_timer_disable(F28335_CPU_TIMER_0_BASE);
	f28335_timer_disable(F28335_CPU_TIMER_1_BASE);

	f28335_timer_disable(F28335_CPU_TIMER_2_BASE);
	f28335_timer_freqence_set(F28335_CPU_TIMER_2_BASE, 0, 0);
	f28335_timer_enable(F28335_CPU_TIMER_2_BASE);

	EINT;
	IER = BIT(13);
	f28335_pie_enable(F28335_PIE_BASE);

	while (1);
}
