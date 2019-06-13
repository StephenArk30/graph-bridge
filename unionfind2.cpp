//
// Created by Stephen Ark on 6/12/2019.
//

#include <fstream>
#include <cstring>
#include <iostream>
#include "unionfind2.h"

unionfind2::unionfind2(const string &file_path) {
    ifstream file;
    file.open(file_path);
    v_num = e_num = 0;
    file >> v_num >> e_num;
    nodes = new node2[v_num];
    edges = new edge2[e_num];
    sets = new set2[v_num];
    int i;
    // init nodes
    for (i = 0; i < v_num; ++i) {
        nodes[i].father = -1;
        nodes[i].head = i;
        nodes[i].level = -1;
        nodes[i].e = -1;
        nodes[i].next = -1;
        sets[i].head = i;
        sets[i].tail = i;
    }
    // init edges
    is_bridge = new bool[e_num];
    for (i = 0; i < e_num; ++i)
        file >> edges[i].node1 >> edges[i].node2;
}

void unionfind2::tarjan_lca() {
    memset(is_bridge, true, sizeof(bool) * e_num);
    for (int i = 0; i < e_num; ++i) {
        if (i % 100000 == 0) cout << "edge " << i << " solved\n";
        int node1 = edges[i].node1;
        int node2 = edges[i].node2;
        if (node1 == node2) { // this is a self loop
            is_bridge[i] = false;
            continue;
        }
        if (nodes[node1].level < 0 && nodes[node2].level < 0) {
            nodes[node1].level = 0;
            union_node(node1, node2, i);
        } else if (nodes[node1].level >= 0 && nodes[node2].level >= 0) {
            if (nodes[node1].head == nodes[node2].head) {
                // in the same tree, find lca node1, node2
                is_bridge[i] = false;
                find_lca(node1, node2);
            } else {
                union_set(node1, node2, i);
            }
        } else if (nodes[node1].level < 0) {
            union_node(node2, node1, i);
        } else {
            union_node(node1, node2, i);
        }
    }
}

void unionfind2::union_set(int node1, int node2, int e) {
    int temp = nodes[node2].head;
    // reverse father
    int p, i;
    int q = node1;
    i = node2;
    while (i > 0) {
        p = nodes[i].father;
        nodes[i].father = q;
        nodes[i].head = nodes[node1].head;
        nodes[i].level = nodes[q].level + 1;
        q = nodes[i].e;
        nodes[i].e = e;
        e = q;
        q = i;
        i = p;
    }
    nodes[sets[nodes[node1].head].tail].next = sets[temp].head;
    sets[nodes[node1].head].tail = sets[temp].tail;
    for (i = sets[temp].head; i != -1; i = nodes[i].next) {
        q = 0;
        for (p = i; nodes[p].head != nodes[node1].head; p = nodes[p].father) ++q;
        nodes[i].level = nodes[p].level + q;
        nodes[i].head = nodes[node1].head;
    }
    sets[temp].head = -1;
    sets[temp].tail = -1;
}

void unionfind2::union_node(int node1, int node2, int e) {
    sets[nodes[node2].head].head = -1;
    sets[nodes[node2].head].tail = -1;

    nodes[sets[nodes[node1].head].tail].next = node2;
    nodes[node2].level = nodes[node1].level + 1;
    nodes[node2].head = nodes[node1].head;
    nodes[node2].father = node1;
    nodes[node2].e = e;

    sets[nodes[node2].head].tail = node2;
}

void unionfind2::find_lca(int node1, int node2) {
    int p = node1;
    int q = node2;
    int temp;
    while (p != q) {
        if (nodes[p].e >= 0) is_bridge[nodes[p].e] = false;
        if (nodes[q].e >= 0) is_bridge[nodes[q].e] = false;
        if (nodes[p].level >= nodes[q].level) {
            temp = p;
            p = nodes[p].father;
        } else {
            temp = q;
            q = nodes[q].father;
        }
        if (temp != sets[nodes[temp].head].head) {
            nodes[temp].father = sets[nodes[temp].head].head;
            nodes[temp].e = -1;
        }
    }
}

void unionfind2::print_bridge() {
    for (int i = 0; i < e_num; ++i)
        if (is_bridge[i]) cout << edges[i].node1 << ' ' << edges[i].node2 << '\n';
}

unionfind2::~unionfind2() {
    delete[] nodes;
    delete[] edges;
    delete[] sets;
    delete[] is_bridge;
}
