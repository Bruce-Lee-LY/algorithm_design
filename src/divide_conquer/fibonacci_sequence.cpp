// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 18:39:37 on Wed, May 25, 2022
//
// Description: fibonacci sequence

#include <stdio.h>

#include "common.h"

static unsigned long long fibonacci_sequence(unsigned long long n) {
    if (!n) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    return fibonacci_sequence(n - 1) + fibonacci_sequence(n - 2);
}

int main() {
    unsigned long long start = 0;
    unsigned long long end = 0;
    unsigned long long result = 0;

    for (unsigned long long i = 0; i < 64; ++i) {
        start = get_time_us();
        result = fibonacci_sequence(i);
        end = get_time_us();
        printf("[%lld]: fibonacci_sequence = %lld, time_cost = %lld us\n", i, result, end - start);
    }

    return 0;
}
