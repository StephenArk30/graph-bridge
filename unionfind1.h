//
// Created by Stephen Ark on 5/31/2019.
//

#ifndef GRAPH_BRIDGE_UNIONFIND1_H
#define GRAPH_BRIDGE_UNIONFIND1_H

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

class unionfind1 {
private:
    list<set *> sets;
    node **nodes;
    int setnum;
    int v_num, e_num;
    node ***edge;

    int bridge_num;
    bool *is_bridge;

    void makeset(node *x);

    void bfsunion(graph &g, int s, int *color, int d);
public:
    explicit unionfind1(const string &file_path);

    ~unionfind1();

    node *makeset(int x);
    set* findset(node *x);

    bool unionset(node *x, node *y, int e);

    void benchmark(graph &g); // 暴力算法

    int getsetnum() { return setnum; }

    void printBridge();
};


#endif //GRAPH_BRIDGE_UNIONFIND1_H
