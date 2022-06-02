// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 18:39:37 on Wed, May 25, 2022
//
// Description: bellman ford

#include <stdio.h>

#include <vector>

#include "common.h"

#define BF_INT_INF (~(0x01 << 31))

static std::vector<std::vector<int>> s_adjacency_matrix = {
    {0, 12, BF_INT_INF, BF_INT_INF, BF_INT_INF, BF_INT_INF, 14},
    {BF_INT_INF, 0, 10, BF_INT_INF, BF_INT_INF, -8, BF_INT_INF},
    {BF_INT_INF, BF_INT_INF, 0, 3, -5, BF_INT_INF, BF_INT_INF},
    {BF_INT_INF, BF_INT_INF, BF_INT_INF, 0, 4, BF_INT_INF, BF_INT_INF},
    {BF_INT_INF, BF_INT_INF, BF_INT_INF, BF_INT_INF, 0, BF_INT_INF, 7},
    {BF_INT_INF, BF_INT_INF, BF_INT_INF, BF_INT_INF, BF_INT_INF, 0, 9},
    {BF_INT_INF, BF_INT_INF, BF_INT_INF, BF_INT_INF, BF_INT_INF, BF_INT_INF, 0}};

static bool bellman_ford(const std::vector<std::vector<int>> &adjacency_matrix) {
    int vertex_num = static_cast<int>(adjacency_matrix.size());
    std::vector<int> dists(vertex_num);
    for (int i = 0; i < vertex_num; ++i) {
        dists[i] = adjacency_matrix[0][i];
    }

    int dist_tmp = 0;
    for (int i = 0; i < vertex_num; ++i) {
        for (int j = 0; j < vertex_num; ++j) {
            for (int k = 0; k < vertex_num; ++k) {
                dist_tmp = (dists[j] == BF_INT_INF || adjacency_matrix[j][k] == BF_INT_INF)
                               ? BF_INT_INF
                               : (dists[j] + adjacency_matrix[j][k]);
                if (dists[k] > dist_tmp) {
                    dists[k] = dist_tmp;
                }
            }
        }
    }

    for (int j = 0; j < vertex_num; ++j) {
        for (int k = 0; k < vertex_num; ++k) {
            dist_tmp = (dists[j] == BF_INT_INF || adjacency_matrix[j][k] == BF_INT_INF)
                           ? BF_INT_INF
                           : (dists[j] + adjacency_matrix[j][k]);
            if (dists[k] > dist_tmp) {
                return false;
            }
        }
    }

    for (int i = 0; i < vertex_num; ++i) {
        printf("%d ", dists[i]);
    }
    printf("\n");

    return true;
}

int main() {
    unsigned long long start = get_time_us();
    printf("bellman_ford = %d\n", bellman_ford(s_adjacency_matrix));
    unsigned long long end = get_time_us();
    printf("time_cost = %lld us\n", end - start);

    return 0;
}
