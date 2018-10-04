#ifndef F28335_H
#define F28335_H

#include <zstack/libc/stdint.h>
#include <zstack/libc/stdbool.h>
#include <zstack/libc/assert.h>

#include <zstack/lld/c2000/c2000.h>

#include <zstack/lld/f28335/delay.h>

#include <zstack/lld/f28335/memory_map.h>

#include <zstack/lld/f28335/vector_table.h>

#include <zstack/lld/f28335/pll.h>
#include <zstack/lld/f28335/pie.h>
#include <zstack/lld/f28335/gpio.h>
#include <zstack/lld/f28335/timer.h>
#include <zstack/lld/f28335/watchdog.h>

#include <zstack/misc/bitops.h>

#define SYSCLKOUT_MAX	(150*1000*1000)

#endif
