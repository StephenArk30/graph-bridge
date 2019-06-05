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
public:
    explicit unionfind(const graph &g);
    ~unionfind();

    node *makeset(int x);
    set* findset(node *x);
    bool unionset(node *x, node *y);

    int getsetnum() { return setnum; }
};


#endif //GRAPH_BRIDGE_UNIONFIND_H
