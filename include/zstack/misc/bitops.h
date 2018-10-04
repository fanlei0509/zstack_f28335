#ifndef BITOPS_H
#define BITOPS_H

#define BIT(pos)				(1 << (pos))

#define BITS_MASK(b, a)			((BIT((b) - (a) + 1) - 1) << a)
#define BITS_CLR(reg, b, a)		(reg) = (reg) & (~BITS_MASK(b, a))

#define BITS_SET(reg, b, a, v)		\
	do {							\
		BITS_CLR(reg, b, a);		\
		(reg) = (reg) | ((v) << a);	\
	} while (0)

#define BITS_GET(reg, b, a)		(((reg) & BITS_MASK(b, a)) >> a)

#endif
