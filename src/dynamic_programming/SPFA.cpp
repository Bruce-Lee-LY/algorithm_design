// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 18:39:37 on Wed, May 25, 2022
//
// Description: SPFA

#include <stdio.h>

#include <queue>
#include <vector>

#include "common.h"

#define SPFA_INT_INF (~(0x01 << 31))

static std::vector<std::vector<int>> s_adjacency_matrix = {
    {0, 12, SPFA_INT_INF, SPFA_INT_INF, SPFA_INT_INF, SPFA_INT_INF, 14},
    {SPFA_INT_INF, 0, 10, SPFA_INT_INF, SPFA_INT_INF, -8, SPFA_INT_INF},
    {SPFA_INT_INF, SPFA_INT_INF, 0, 3, -5, SPFA_INT_INF, SPFA_INT_INF},
    {SPFA_INT_INF, SPFA_INT_INF, SPFA_INT_INF, 0, 4, SPFA_INT_INF, SPFA_INT_INF},
    {SPFA_INT_INF, SPFA_INT_INF, SPFA_INT_INF, SPFA_INT_INF, 0, SPFA_INT_INF, 7},
    {SPFA_INT_INF, SPFA_INT_INF, SPFA_INT_INF, SPFA_INT_INF, SPFA_INT_INF, 0, 9},
    {SPFA_INT_INF, SPFA_INT_INF, SPFA_INT_INF, SPFA_INT_INF, SPFA_INT_INF, SPFA_INT_INF, 0}};

static bool SPFA(const std::vector<std::vector<int>> &adjacency_matrix) {
    int vertex_num = static_cast<int>(adjacency_matrix.size());
    std::vector<bool> visited(vertex_num, false);
    std::vector<int> dists(vertex_num);
    for (int i = 0; i < vertex_num; ++i) {
        dists[i] = adjacency_matrix[0][i];
    }

    int dist_tmp = 0;
    int idx = 1;
    int cnt = 0;
    std::queue<int> que;
    que.push(idx);
    que.push(cnt);
    while (!que.empty()) {
        idx = que.front();
        que.pop();
        visited[idx] = false;

        cnt = que.front();
        que.pop();
        if (cnt > vertex_num) {
            return false;
        }

        for (int i = 0; i < vertex_num; ++i) {
            dist_tmp = (dists[idx] == SPFA_INT_INF || adjacency_matrix[idx][i] == SPFA_INT_INF)
                           ? SPFA_INT_INF
                           : (dists[idx] + adjacency_matrix[idx][i]);
            if (dists[i] > dist_tmp) {
                dists[i] = dist_tmp;
                if (!visited[i]) {
                    que.push(i);
                    que.push(cnt + 1);
                    visited[i] = true;
                }
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
    printf("SPFA = %d\n", SPFA(s_adjacency_matrix));
    unsigned long long end = get_time_us();
    printf("time_cost = %lld us\n", end - start);

    return 0;
}
