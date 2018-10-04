#include <zstack/lld/f28335/f28335.h>

struct f28335_pie_register {
	uint16_t ctrl;
	uint16_t ack;
	struct {
		uint16_t ier;
		uint16_t ifr;
	} group[12];
};

#define PIE_VECTOR_TABLE_ENABLE		BIT(0)

void f28335_pie_enable(uint32_t base)
{
	struct f28335_pie_register *pie = (void *)base;

	pie->ctrl = PIE_VECTOR_TABLE_ENABLE;
}

void f28335_pie_interrupt_enable(uint32_t base, enum f28335_pie_interrupt intr)
{
	struct f28335_pie_register *pie = (void *)base;

	uint16_t group = (intr >> 8) & 0xFF;
	uint16_t num = intr & 0xFF;

	pie->group[group].ier |= BIT(num);
}

void f28335_pie_ack(uint32_t base, enum f28335_pie_interrupt intr)
{
	struct f28335_pie_register *pie = (void *)base;

	uint16_t group = (intr >> 8) & 0xFF;

	pie->ack |= BIT(group);
}

void f28335_pie_disable(void)
{

}
