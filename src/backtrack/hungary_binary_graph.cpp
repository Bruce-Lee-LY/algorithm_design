// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 18:39:37 on Wed, May 25, 2022
//
// Description: hungary binary graph

#include <stdio.h>

#include <vector>

#include "common.h"

#define H_NO_LINK_FLAG (-1)

static std::vector<std::vector<int>> binary_graph = {
    {1, 1, 0, 0, 0}, {1, 0, 0, 0, 0}, {0, 0, 1, 0, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 1, 0}};

static int vertex_num = static_cast<int>(binary_graph.size());
static std::vector<bool> visited(vertex_num, false);
static std::vector<int> matched_right(vertex_num, H_NO_LINK_FLAG);

static bool hungary(int idx) {
    for (int i = 0; i < vertex_num; ++i) {
        if (!visited[i] && binary_graph[idx][i]) {
            visited[i] = true;
            if (matched_right[i] == H_NO_LINK_FLAG || hungary(matched_right[i])) {
                matched_right[i] = idx;
                return true;
            }
        }
    }

    return false;
}

static void max_match() {
    int cnt = 0;
    for (int i = 0; i < vertex_num; ++i) {
        std::vector<bool>(vertex_num, false).swap(visited);
        if (hungary(i)) {
            cnt++;
        }
        printf("[%d]: %d\n", i, cnt);
    }

    for (int i = 0; i < vertex_num; ++i) {
        printf("[%d]---[%d]\n", matched_right[i], i);
    }
}

int main() {
    unsigned long long start = get_time_us();
    max_match();
    unsigned long long end = get_time_us();
    printf("time_cost = %lld us\n", end - start);

    return 0;
}
