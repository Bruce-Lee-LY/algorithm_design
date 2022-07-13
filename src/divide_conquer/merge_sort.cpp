// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 23:21:55 on Wed, Jul 13, 2022
//
// Description: merge sort ascend

#include <stdio.h>

#include <vector>

#include "common.h"

static std::vector<int> s_arr = {5, 7, 1, 9, 2, 6, 8, 4, 3};

static void merge_sort(std::vector<int> &arr, const int &start, const int &end) {
    if (start >= end) {
        return;
    }

    int mid = (start + end) >> 1;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);

    std::vector<int> tmp(end - start + 1, 0);
    int p1 = start, p2 = mid + 1, i = 0;

    while (p1 <= mid && p2 <= end) {
        tmp[i++] = (arr[p1] > arr[p2]) ? arr[p2++] : arr[p1++];
    }

    while (p1 <= mid) {
        tmp[i++] = arr[p1++];
    }

    while (p2 <= end) {
        tmp[i++] = arr[p2++];
    }

    for (i = 0; i < end - start + 1; ++i) {
        arr[start + i] = tmp[i];
    }
}

int main() {
    unsigned long long start = get_time_us();
    merge_sort(s_arr, 0, static_cast<int>(s_arr.size() - 1));
    unsigned long long end = get_time_us();
    printf("time_cost = %lld us\n", end - start);

    for (size_t i = 0; i < s_arr.size(); ++i) {
        printf("%d ", s_arr[i]);
    }

    return 0;
}
