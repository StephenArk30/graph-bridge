//
// Created by Stephen Ark on 6/12/2019.
//

#ifndef GRAPH_BRIDGE_UNIONFIND2_H
#define GRAPH_BRIDGE_UNIONFIND2_H

#include <string>

using namespace std;

struct node2 {
    int father;
    int head;
    int level; // level == -1 not in tree
    int e;
    int next;
};

struct edge2 {
    int node1, node2;
};

struct set2 {
    int head;
    int tail;
};

class unionfind2 {
private:
    node2 *nodes;
    edge2 *edges;
    set2 *sets;
    int v_num;
    int e_num;
    bool *is_bridge;

    void union_set(int node1, int node2, int e);

    void union_node(int node1, int node2, int e);

    void find_lca(int node1, int node2);

public:
    explicit unionfind2(const string &file_path);

    ~unionfind2();

    void tarjan_lca();

    void print_bridge();
};


#endif //GRAPH_BRIDGE_UNIONFIND2_H
