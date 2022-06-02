// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 18:39:37 on Wed, May 25, 2022
//
// Description: KM binary graph

#include <stdio.h>

#include <algorithm>
#include <vector>

#include "common.h"

#define KM_NO_LINK_FLAG (-1)
#define KM_INF 0x3F3F3F3F

static std::vector<std::vector<int>> binary_graph = {{3, KM_INF, 4}, {2, 1, 3}, {KM_INF, KM_INF, 5}};

static int vertex_num = static_cast<int>(binary_graph.size());
static std::vector<int> weights_left(vertex_num, 0);
static std::vector<bool> visited_left(vertex_num, false);
static std::vector<int> matched_left(vertex_num, KM_NO_LINK_FLAG);

static std::vector<int> weights_right(vertex_num, 0);
static std::vector<bool> visited_right(vertex_num, false);
static std::vector<int> matched_right(vertex_num, KM_NO_LINK_FLAG);

static std::vector<int> slack(vertex_num, KM_INF);

static bool hungary(int idx) {
    visited_left[idx] = true;
    for (int i = 0; i < vertex_num; ++i) {
        if (!visited_right[i] && binary_graph[idx][i] != KM_INF) {
            int tmp = weights_left[idx] + weights_right[i] - binary_graph[idx][i];
            if (tmp == 0) {
                visited_right[i] = true;

                if (matched_right[i] == KM_NO_LINK_FLAG || hungary(matched_right[i])) {
                    matched_left[idx] = i;
                    matched_right[i] = idx;
                    return true;
                }
            } else if (tmp > 0) {
                slack[i] = std::min(slack[i], tmp);
            }
        }
    }

    return false;
}

static int KM() {
    for (int i = 0; i < vertex_num; ++i) {
        for (int j = 0; j < vertex_num; ++j) {
            if (binary_graph[i][j] == KM_INF) {
                continue;
            }
            weights_left[i] = std::max(weights_left[i], binary_graph[i][j]);
        }
    }

    for (int i = 0; i < vertex_num; ++i) {
        std::vector<int>(vertex_num, KM_INF).swap(slack);
        while (true) {
            std::vector<bool>(vertex_num, false).swap(visited_left);
            std::vector<bool>(vertex_num, false).swap(visited_right);

            if (hungary(i)) {
                break;
            }

            int cost = KM_INF;
            for (int j = 0; j < vertex_num; ++j) {
                if (!visited_right[j] && cost > slack[j]) {
                    cost = slack[j];
                }
            }

            for (int j = 0; j < vertex_num; ++j) {
                if (visited_left[j]) {
                    weights_left[j] -= cost;
                }
            }

            for (int j = 0; j < vertex_num; ++j) {
                if (visited_right[j]) {
                    weights_right[j] += cost;
                } else {
                    slack[j] -= cost;
                }
            }
        }
    }

    for (int i = 0; i < vertex_num; i++) {
        printf("[%d]---[%d]\n", matched_right[i], i);
    }

    int best_weight = 0;
    for (int i = 0; i < vertex_num; i++) {
        if (matched_left[i] != KM_NO_LINK_FLAG) {
            best_weight += binary_graph[matched_right[i]][i];
        }
    }

    return best_weight;
}

int main() {
    unsigned long long start = get_time_us();
    printf("KM = %d\n", KM());
    unsigned long long end = get_time_us();
    printf("time_cost = %lld us\n", end - start);

    return 0;
}
