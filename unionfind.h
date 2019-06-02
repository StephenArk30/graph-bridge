//
// Created by Stephen Ark on 5/31/2019.
//

#ifndef GRAPH_BRIDGE_UNIONFIND_H
#define GRAPH_BRIDGE_UNIONFIND_H

#include <vector>

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
     vector<set*> sets;
public:
    unionfind();

    ~unionfind();
    void makeset(int x);
    set* findset(node *x);
    bool unionset(node *x, node *y);
};


#endif //GRAPH_BRIDGE_UNIONFIND_H
