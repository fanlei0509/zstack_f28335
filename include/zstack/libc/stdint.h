#ifndef STDINT_H
#define STDINT_H

typedef short				int16_t;
typedef unsigned short		uint16_t;
typedef long				int32_t;
typedef unsigned long		uint32_t;
typedef long long			int64_t;
typedef unsigned long long	uint64_t;

#define INT16_MAX			0x7fff
#define INT16_MIN			(-INT16_MAX-1)
#define UINT16_MAX			0xffff

#define INT32_MAX			0x7fffffff
#define INT32_MIN			(-INT32_MAX-1)
#define UINT32_MAX			0xffffffff

#define INT64_MAX			0x7fffffffffffffff
#define INT64_MIN			(-INT64_MAX-1)
#define UINT64_MAX			0xffffffffffffffff

#endif
