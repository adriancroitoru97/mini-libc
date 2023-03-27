/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __TIME_H__
#define __TIME_H__  1

#ifdef __cplusplus
extern "C" {
#endif

typedef long            __time32_t;
typedef long long       __time64_t;

#ifndef _CRT_NO_TIME_T
    #ifdef _USE_32BIT_TIME_T
        typedef __time32_t time_t;
    #else
        typedef __time64_t time_t;
    #endif
#endif

#ifndef _CRT_NO_TIME_T
    struct timespec
    {
        time_t tv_sec;  // Seconds - >= 0
        long   tv_nsec; // Nanoseconds - [0, 999999999]
    };
#endif

int nanosleep(const struct timespec *req, struct timespec *rem);

#ifdef __cplusplus
}
#endif

#endif
