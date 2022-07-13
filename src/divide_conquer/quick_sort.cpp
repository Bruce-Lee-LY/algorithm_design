// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 18:39:37 on Wed, May 25, 2022
//
// Description: quick sort ascend

#include <stdio.h>

#include <vector>

#include "common.h"

static std::vector<int> s_arr = {5, 7, 1, 9, 2, 6, 8, 4, 3};

static void quick_sort(std::vector<int> &arr, int start, int end) {
    if (start >= end) {
        return;
    }

    int left = start;
    int right = end;
    int base = arr[start];

    while (left < right) {
        while (arr[right] >= base && left < right) {
            right--;
        }

        while (arr[left] <= base && left < right) {
            left++;
        }

        if (left < right) {
            _swap(arr[left], arr[right]);
        }
    }

    arr[start] = arr[left];
    arr[left] = base;
    quick_sort(arr, start, left - 1);
    quick_sort(arr, left + 1, end);
}

int main() {
    unsigned long long start = get_time_us();
    quick_sort(s_arr, 0, static_cast<int>(s_arr.size() - 1));
    unsigned long long end = get_time_us();
    printf("time_cost = %lld us\n", end - start);

    for (size_t i = 0; i < s_arr.size(); ++i) {
        printf("%d ", s_arr[i]);
    }

    return 0;
}
