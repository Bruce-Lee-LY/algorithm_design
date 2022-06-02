// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 18:39:37 on Wed, May 25, 2022
//
// Description: coin change

#include <stdio.h>
#include <string.h>

#include <algorithm>

#include "common.h"

#define MONEY_UNIT_NUM 7

static int money_unit[MONEY_UNIT_NUM] = {100, 50, 20, 10, 5, 2, 1};
static int money_own[MONEY_UNIT_NUM] = {20, 3, 0, 6, 5, 8, 16};

typedef struct {
    bool changed;
    int unit_cnt[MONEY_UNIT_NUM];
} cc_result_s;

static void coin_change(int money, cc_result_s *cc_result) {
    if (!cc_result || money <= 0) {
        printf("input params error\n");
    }

    memset((void *)cc_result, 0x00, sizeof(cc_result_s));

    printf("money = %d\n", money);
    int money_need = money;
    for (int i = 0; i < MONEY_UNIT_NUM; ++i) {
        cc_result->unit_cnt[i] = std::min(money_own[i], money_need / money_unit[i]);
        money_need -= cc_result->unit_cnt[i] * money_unit[i];
        printf("unit_cnt[%d] = %d, money_need = %d\n", money_unit[i], cc_result->unit_cnt[i], money_need);
    }

    if (money_need != 0) {
        cc_result->changed = true;
    }
    printf("changed = %d\n", static_cast<int>(cc_result->changed));
}

int main() {
    cc_result_s cc_result;

    unsigned long long start = get_time_us();
    coin_change(1523, &cc_result);
    unsigned long long end = get_time_us();
    printf("time_cost = %lld us\n", end - start);

    start = get_time_us();
    coin_change(36666, &cc_result);
    end = get_time_us();
    printf("time_cost = %lld us\n", end - start);

    return 0;
}
