#include <zstack/lld/f28335/f28335.h>

static void dummy_isr(void)
{
	while (1);
}

void f28335_vector_table_init(uint32_t base)
{
	isr_func *f28335_vector_table = (void *)base;
	int i;

	EALLOW;
	for (i = 0; i < 128; i++) {
		f28335_vector_table[i] = dummy_isr;
	}
	EDIS;
}

void f28335_vector_table_register(uint32_t base, enum f28335_vector num, isr_func func)
{
	EALLOW;
	isr_func *f28335_vector_table = (void *)base;
	f28335_vector_table[num] = func;
	EDIS;
}
