// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 18:39:37 on Wed, May 25, 2022
//
// Description: dijkstra

#include <stdio.h>

#include <limits>
#include <queue>
#include <vector>

#include "common.h"

#define DIJ_NO_EDGE_FLAG -1
#define DIJ_GRAPH_NODE_NUM 11

class dij_node {
public:
    dij_node(int in_idx = 0, int in_dist = 0) : visited(false) {
        this->idx = in_idx;
        this->dist = in_dist;
    }

    ~dij_node() = default;

    bool operator<(const dij_node &node) const {
        return dist > node.dist;
    }

    int idx;
    int dist;
    bool visited;
};

class dij_path {
public:
    dij_path(int in_pre_idx = 0, int in_dist = std::numeric_limits<int>::max()) {
        this->pre_idx = in_pre_idx;
        this->dist = in_dist;
    }

    ~dij_path() = default;

    int pre_idx;
    int dist;
};

static int dijkstra(const std::vector<std::vector<int>> &graph) {
    int node_num = static_cast<int>(graph.size());
    std::vector<dij_path> paths(node_num);
    std::vector<int> path_idxs;
    dij_node node_top;
    int min_dist = 0;
    std::priority_queue<dij_node, std::vector<dij_node>> prior_que;
    prior_que.push(dij_node(0, 0));
    while (!prior_que.empty()) {
        node_top = prior_que.top();
        prior_que.pop();

        if (node_top.idx == node_num - 1) {
            break;
        }

        if (node_top.visited) {
            continue;
        }
        node_top.visited = true;

        for (int i = 0; i < node_num; ++i) {
            min_dist = node_top.dist + graph[node_top.idx][i];
            if (graph[node_top.idx][i] != DIJ_NO_EDGE_FLAG && min_dist < paths[i].dist) {
                prior_que.push(dij_node(i, min_dist));
                paths[i].pre_idx = node_top.idx;
                paths[i].dist = min_dist;
            }
        }
    }

    int idx = node_num - 1;
    path_idxs.push_back(idx);
    while (true) {
        idx = paths[idx].pre_idx;
        path_idxs.push_back(idx);
        if (idx == 0) {
            break;
        }
    }

    printf("dijkstra_path: ");
    for (auto iter = path_idxs.rbegin(); iter != path_idxs.rend(); ++iter) {
        printf("%d ", *iter);
    }
    printf("\n");

    return paths[node_num - 1].dist;
}

int main() {
    std::vector<std::vector<int>> graph(DIJ_GRAPH_NODE_NUM);
    for (int i = 0; i < DIJ_GRAPH_NODE_NUM; ++i) {
        graph[i].resize(DIJ_GRAPH_NODE_NUM);
    }

    for (int i = 0; i < DIJ_GRAPH_NODE_NUM; ++i) {
        for (int j = 0; j < DIJ_GRAPH_NODE_NUM; ++j) {
            graph[i][j] = DIJ_NO_EDGE_FLAG;
        }
    }

    graph[0][1] = 2;
    graph[0][2] = 3;
    graph[0][3] = 4;
    graph[1][2] = 3;
    graph[1][4] = 7;
    graph[1][5] = 2;
    graph[2][5] = 9;
    graph[2][6] = 2;
    graph[3][6] = 2;
    graph[4][7] = 3;
    graph[4][8] = 3;
    graph[5][6] = 1;
    graph[5][8] = 3;
    graph[6][8] = 5;
    graph[6][9] = 1;
    graph[7][10] = 3;
    graph[8][10] = 2;
    graph[9][8] = 2;
    graph[9][10] = 2;

    unsigned long long start = get_time_us();
    printf("dijkstra = %d\n", dijkstra(graph));
    unsigned long long end = get_time_us();
    printf("time_cost = %lld us\n", end - start);

    return 0;
}
