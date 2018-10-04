#include <zstack/lld/f28335/f28335.h>

static interrupt void cpu_timer_0_isr(void)
{
	static uint16_t status;

	if (status)
		f28335_gpio_output(F28335_GPIO_BASE, F28335_GPIO_0, F28335_GPIO_LEVEL_LOW);
	else
		f28335_gpio_output(F28335_GPIO_BASE, F28335_GPIO_0, F28335_GPIO_LEVEL_HIGH);

	status = !status;

	f28335_pie_ack(F28335_PIE_BASE, F28335_PIE_INT_TIMER0);
}

int timer_0_led_blink(void)
{
	f28335_watchdog_disable(F28335_WATCHDOG_BASE);

	f28335_pll_peripheral_enable(F28335_PLL_BASE, F28335_IP_GPIO);

	f28335_gpio_func(F28335_GPIO_BASE, F28335_GPIO_0, F28335_GPIO_FUNC_GPIO);

	f28335_gpio_dir(F28335_GPIO_BASE, F28335_GPIO_0, F28335_GPIO_OUTPUT);

	f28335_vector_table_init(F28335_PIE_VECTOR_BASE);
	f28335_vector_table_register(F28335_PIE_VECTOR_BASE, F28335_VECTOR_TIMER_0, cpu_timer_0_isr);

	f28335_pll_cpu_freq_get(F28335_PLL_BASE, 30*1000*1000U);

	f28335_timer_disable(F28335_CPU_TIMER_1_BASE);
	f28335_timer_disable(F28335_CPU_TIMER_2_BASE);

	f28335_timer_disable(F28335_CPU_TIMER_0_BASE);
	f28335_timer_freqence_set(F28335_CPU_TIMER_0_BASE, 0, 0);
	f28335_timer_enable(F28335_CPU_TIMER_0_BASE);

	EINT;
	IER = BIT(0);
	f28335_pie_enable(F28335_PIE_BASE);
	f28335_pie_interrupt_enable(F28335_PIE_BASE, F28335_PIE_INT_TIMER0);

	while (1);
}
