//
// Created by Stephen Ark on 5/31/2019.
//

#include <fstream>
#include <queue>
#include "graph.h"

// create adjacency list
graph::graph(string &filename) : data_file(filename) {
    ifstream file;
    file.open(data_file);
    v_num = e_num = 0;
    file >> v_num >> e_num;
    adj_list = new list<int>[v_num];
    int temp_node1, temp_node2;
    for (int i = 0; i < v_num; ++i) {
        file >> temp_node1 >> temp_node2;
        adj_list[temp_node1].push_back(temp_node2);
        adj_list[temp_node2].push_back(temp_node1);
    }
}

/**
 * color: 0 white, 1 grey, 2 black
 * param: s: start node
 * return node color array
 * */
int *graph::bfs(int s, int *color) {
    color[s] = 1;
    queue<int> q;
    q.push(s);
    int current_node;
    list<int>::iterator iter;
    while (!q.empty()) {
        current_node = q.front();
        q.pop();
        for (iter = adj_list[current_node].begin(); iter != adj_list[current_node].end(); iter++) {
            if (color[*iter] == 0) {
                color[*iter] = 1;
                q.push(*iter);
            }
        }
        color[current_node] = 2;
    }
    return color;
}

graph::~graph() {
    adj_list->clear();
    delete[] adj_list;
}

int graph::get_connected_num() {
    int connected_num = 0;
    int *color = new int[v_num];
    int s = 0;
    while (s >= 0) {
        ++connected_num;
        bfs(s, color);
        s = get_next_start(color);
    }
    delete[] color;
    return connected_num;
}

int graph::get_next_start(const int *color) {
    for (int i = 0; i < v_num; ++i)
        if (color[i] == 0) return i;
    return -1;
}

vector<int *> graph::benchmark() {
    list<int>::iterator iter, jter;
    list<int> current_adj, delete_adj;
    int delete_node;
    int connected_num = get_connected_num();
    int temp_connected_num;
    vector<int *> bridge;

    for (int current_node = 0; current_node < v_num; ++current_node) {
        current_adj = adj_list[current_node];
        for (iter = current_adj.begin(); iter != current_adj.end(); iter++) {
            delete_node = *iter;
            if (delete_node < current_node) continue; // 保证不会删除重复的边
            // delete edge
            delete_adj = adj_list[delete_node];
            for (jter = delete_adj.begin(); jter != delete_adj.end(); jter++) {
                if (*jter == current_node) {
                    delete_adj.erase(jter);
                    break;
                }
            }
            current_adj.erase(iter);
            // judge if is bridge
            temp_connected_num = get_connected_num();
            if (connected_num < temp_connected_num) {
                int *e = new int[2];
                e[0] = current_node;
                e[1] = delete_node;
                bridge.push_back(e);
            }
            // restore edge
            current_adj.insert(iter, current_node);
            delete_adj.insert(jter, delete_node);
        }
    }
}
