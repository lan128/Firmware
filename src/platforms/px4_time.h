#pragma once

#include <sys/types.h>
#include <time.h>

#ifdef __PX4_LINUX

#define px4_clock_gettime clock_gettime
#define px4_clock_settime clock_settime

#elif defined(__PX4_QURT)

#define CLOCK_REALTIME 1

__BEGIN_DECLS

#if !defined(__cplusplus)
struct timespec
{
	time_t tv_sec;
	long tv_nsec;
};
#endif
int px4_clock_gettime(clockid_t clk_id, struct timespec *tp);
int px4_clock_settime(clockid_t clk_id, struct timespec *tp);

__EXPORT int usleep(useconds_t usec);
__EXPORT unsigned int sleep(unsigned int sec);

__END_DECLS
#endif
