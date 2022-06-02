// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 18:39:37 on Wed, May 25, 2022
//
// Description: fibonacci sequence

#include <stdio.h>
#include <string.h>

#include "common.h"

#define INTER_RESULT_NUM 64

static unsigned long long fibonacci_sequence(unsigned long long n, unsigned long long *inter_result) {
    if (!n) {
        inter_result[0] = 0;
        return 0;
    }

    if (n == 1) {
        inter_result[1] = 1;
        return 1;
    }

    if (!inter_result[n]) {
        inter_result[n] = fibonacci_sequence(n - 1, inter_result) + fibonacci_sequence(n - 2, inter_result);
    }

    return inter_result[n];
}

int main() {
    unsigned long long start = 0;
    unsigned long long end = 0;
    unsigned long long result = 0;
    unsigned long long inter_result[INTER_RESULT_NUM];

    for (unsigned long long i = 0; i < INTER_RESULT_NUM; ++i) {
        memset((void *)inter_result, 0x00, sizeof(unsigned long long) * INTER_RESULT_NUM);
        start = get_time_us();
        result = fibonacci_sequence(i, inter_result);
        end = get_time_us();
        printf("[%lld]: fibonacci_sequence = %lld, time_cost = %lld us\n", i, result, end - start);
    }

    return 0;
}
