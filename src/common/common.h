// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 18:39:37 on Wed, May 25, 2022
//
// Description: common

#ifndef __ALGORITHM_DESIGN_COMMON_H__
#define __ALGORITHM_DESIGN_COMMON_H__

#include <stddef.h>
#include <sys/time.h>

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

inline unsigned long long get_time_us() {
    struct timeval time;
    if (gettimeofday(&time, NULL) == -1) {
        return 0;
    }

    return (unsigned long long)time.tv_sec * 1000000 + (unsigned long long)time.tv_usec;
}

inline double get_time_ms() {
    return (double)get_time_us() * .001;
}

inline double get_time_s() {
    return (double)get_time_us() * .000001;
}

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // __ALGORITHM_DESIGN_COMMON_H__
