//
// Created by Stephen Ark on 5/31/2019.
//

#include <fstream>
#include <cstring>
#include <queue>
#include <iostream>
#include "unionfind1.h"

unionfind1::unionfind1(const string &file_path) : setnum(0) {
    ifstream file;
    file.open(file_path);
    v_num = e_num = 0;
    file >> v_num >> e_num;

    sets.clear();
    nodes = new node *[v_num];
    is_bridge = new bool[e_num];
    bridge_num = 0;
    edge = new node **[e_num];
    int i, j, k;
    for (i = 0; i < e_num; ++i) {
        edge[i] = new node *[2];
        file >> j >> k;
        edge[i][0] = nodes[j];
        edge[i][1] = nodes[k];
    }

    for (i = 0; i < v_num; i++)
        nodes[i] = makeset(i);
    setnum = i;
    bridge_num = e_num;
    for (i = 0; i < e_num; i++)
        if (edge[i][0]->data > edge[i][1]->data)
            if (unionset(edge[i][0], edge[i][1], i)) setnum--;
}

node *unionfind1::makeset(int x) {
    node *temp_node = new node{
        x, nullptr, nullptr
    };
    set *temp_set = new set {
        temp_node, temp_node
    };
    temp_node->head = temp_set;
    sets.push_back(temp_set);
    return temp_node;
}


set *unionfind1::findset(node *x) {
    return x->head;
}

bool unionfind1::unionset(node *x, node *y, int e) {
    set *set1 = findset(x);
    set *set2 = findset(y);
    if (set1 == nullptr || set2 == nullptr)
        return false;
    if (set1->head == set2->head && e >= 0) {
        is_bridge[e] = false;
        bridge_num--;
        return false;
    }
    (set1->tail)->next = set2->head;
    for (node *i = set2->head; i != nullptr; i = i->next)
        i->head = set1;
    set1->tail = set2->tail;
    set2 = nullptr;
    return true;
}

unionfind1::~unionfind1() {
    list<set *>::iterator iter;
    for (iter = sets.begin(); iter != sets.end(); iter++) {
        node *nd, *next = nullptr;
        for (nd = (*iter)->head; nd->next != nullptr; nd = next) {
            next = nd->next;
            delete (nd);
        }
        delete (*iter);
    }
}

void unionfind1::benchmark(graph &g) {
    memset(is_bridge, true, sizeof(bool) * e_num);
    node *p;
    node *node1, *node2;
    for (int i = 0; i < e_num; ++i) {
        if (!is_bridge[i]) continue;
        node1 = edge[i][0];
        node2 = edge[i][1];
        int *color = new int[v_num];
        memset(color, 2, sizeof(int) * v_num);
        for (p = findset(node1)->head; p != nullptr; p = p->next) {
            makeset(p);
            color[p->data] = 0;
        }
        bfsunion(g, node1->data, color, node2->data);
        if (findset(node1) == findset(node2)) is_bridge[i] = false;
        delete[] color;
    }
}

void unionfind1::makeset(node *x) {
    set *temp_set = new set{
            x, x
    };
    x->head = temp_set;
    sets.push_back(temp_set);
}

void unionfind1::bfsunion(graph &g, int s, int *color, int d) {
    queue<int> q;
    q.push(s);
    int current_node;
    list<int>::iterator iter;
    while (!q.empty()) {
        current_node = q.front();
        q.pop();
        for (iter = g.adj_list[current_node].begin(); iter != g.adj_list[current_node].end(); ++iter) {
            if (*iter == d) continue; // the edge deleted
            if (color[*iter] == 0) {
                color[*iter] = 1;
                q.push(*iter);
                unionset(nodes[current_node], nodes[*iter], -1);
            }
        }
        color[current_node] = 2;
    }
}

void unionfind1::printBridge() {
    for (int i = 0; i < e_num; ++i)
        if (is_bridge[i]) cout << edge[i][0] << ' ' << edge[i][1] << '\n';
}
