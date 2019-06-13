//
// Created by Stephen Ark on 6/12/2019.
//

#ifndef GRAPH_BRIDGE_UNIONFIND2_H
#define GRAPH_BRIDGE_UNIONFIND2_H

#include <string>

using namespace std;

struct node {
    int father;
    int head;
    int level; // level == -1 not in tree
    int e;
    int next;
};

struct edge {
    int node1, node2;
};

struct set {
    int head;
    int tail;
    int size;
};

class unionfind {
private:
    node *nodes;
    edge *edges;
    set *sets;
    int v_num;
    int e_num;
    bool *is_bridge;

    void union_set(int node1, int node2, int e);

    void union_node(int node1, int node2, int e);

    void find_lca(int node1, int node2);

public:
    explicit unionfind(const string &file_path);

    unionfind(int vn, int en);

    ~unionfind();

    void tarjan_lca();

    void print_bridge();
};


#endif //GRAPH_BRIDGE_UNIONFIND2_H
