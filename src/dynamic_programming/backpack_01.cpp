// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 18:39:37 on Wed, May 25, 2022
//
// Description: backpack 01

#include <stdio.h>

#include <algorithm>
#include <vector>

#include "common.h"

static int s_capacity = 17;
static std::vector<int> s_weights = {0, 3, 4, 7, 8, 9};
static std::vector<int> s_prices = {0, 4, 5, 10, 11, 13};

static int backpack_01(int capacity, const std::vector<int> &weights, const std::vector<int> &prices) {
    int product_num = static_cast<int>(weights.size());
    std::vector<int> max_prices(capacity + 1, 0);
    for (int i = 1; i <= product_num; ++i) {
        for (int j = capacity; j >= weights[i]; --j) {
            max_prices[j] = std::max(max_prices[j - weights[i]] + prices[i], max_prices[j]);
        }
    }

    for (int j = 0; j <= capacity; ++j) {
        printf("capacity[%d]: max_price %d\n", j, max_prices[j]);
    }

    return max_prices[capacity];
}

int main() {
    unsigned long long start = get_time_us();
    printf("backpack_01 = %d\n", backpack_01(s_capacity, s_weights, s_prices));
    unsigned long long end = get_time_us();
    printf("time_cost = %lld us\n", end - start);

    return 0;
}
