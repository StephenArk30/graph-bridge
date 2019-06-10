//
// Created by Stephen Ark on 5/31/2019.
//

#ifndef GRAPH_BRIDGE_UNIONFIND_H
#define GRAPH_BRIDGE_UNIONFIND_H

#include <list>
#include "graph.h"

using namespace std;

struct node;
struct set;

struct node {
    int data;
    node *next;
    set *head;
};

struct set {
    node *head;
    node *tail;
};

class unionfind {
private:
    list<set *> sets;
    node **nodes;
    int setnum;
    int v_num, e_num;
    node ***edge;

    int bridge_num;
    bool *is_bridge;

    void makeset(node *x);

    void bfsunion(graph &g, int s, int *color);
public:
    explicit unionfind(const string &file_path);
    ~unionfind();

    node *makeset(int x);
    set* findset(node *x);

    bool unionset(node *x, node *y, int e);

    void benchmark(graph &g); // 暴力算法

    int getsetnum() { return setnum; }
};


#endif //GRAPH_BRIDGE_UNIONFIND_H
