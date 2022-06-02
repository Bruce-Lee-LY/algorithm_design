// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 18:39:37 on Wed, May 25, 2022
//
// Description: floyd

#include <stdio.h>

#include <vector>

#include "common.h"

#define F_INT_INF (~(0x01 << 31))

static std::vector<std::vector<int>> s_adjacency_matrix = {{0, 12, F_INT_INF, F_INT_INF, F_INT_INF, 16, 14},
                                                           {12, 0, 10, F_INT_INF, F_INT_INF, 7, F_INT_INF},
                                                           {F_INT_INF, 10, 0, 3, 5, 6, F_INT_INF},
                                                           {F_INT_INF, F_INT_INF, 3, 0, 4, F_INT_INF, F_INT_INF},
                                                           {F_INT_INF, F_INT_INF, 5, 4, 0, 2, 8},
                                                           {16, 7, 6, F_INT_INF, 2, 0, 9},
                                                           {14, F_INT_INF, F_INT_INF, F_INT_INF, 8, 9, 0}};

static void floyd(const std::vector<std::vector<int>> &adjacency_matrix) {
    int vertex_num = static_cast<int>(adjacency_matrix.size());
    std::vector<std::vector<int>> dists(vertex_num, std::vector<int>(vertex_num));
    int dist_tmp = 0;

    for (int i = 0; i < vertex_num; ++i) {
        for (int j = 0; j < vertex_num; ++j) {
            dists[i][j] = adjacency_matrix[i][j];
        }
    }

    for (int i = 0; i < vertex_num; ++i) {
        for (int j = 0; j < vertex_num; ++j) {
            for (int k = 0; k < vertex_num; ++k) {
                dist_tmp =
                    (dists[j][i] == F_INT_INF || dists[i][k] == F_INT_INF) ? F_INT_INF : (dists[j][i] + dists[i][k]);
                if (dists[j][k] > dist_tmp) {
                    dists[j][k] = dist_tmp;
                }
            }
        }
    }

    for (int i = 0; i < vertex_num; ++i) {
        for (int j = 0; j < vertex_num; ++j) {
            printf("%d\t", dists[i][j]);
        }
        printf("\n");
    }
}

int main() {
    unsigned long long start = get_time_us();
    floyd(s_adjacency_matrix);
    unsigned long long end = get_time_us();
    printf("time_cost = %lld us\n", end - start);

    return 0;
}
