//
// Created by Stephen Ark on 5/31/2019.
//

#include "unionfind.h"

unionfind::unionfind(const graph &g) : setnum(0) {
    sets.clear();
    nodes = new node *[g.v_num];
    int v;
    for (v = 0; v < g.v_num; v++)
        nodes[v] = makeset(v);
    setnum = v;
    for (v = 0; v < g.v_num; v++)
        for (auto e :g.adj_list[v])
            if (nodes[e]->data > nodes[v]->data)
                if (unionset(nodes[v], nodes[e])) setnum--;
}

node *unionfind::makeset(int x) {
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

set *unionfind::findset(node *x) {
    return x->head;
}

bool unionfind::unionset(node *x, node *y) {
    set *set1 = findset(x);
    set *set2 = findset(y);
    if (set1 == nullptr || set2 == nullptr)
        return false;
    if (set1->head == set2->head)
        return false;
    (set1->tail)->next = set2->head;
    for (node *i = set2->head; i != nullptr; i = i->next)
        i->head = set1;
    set1->tail = set2->tail;
    set2 = nullptr;
    return true;
}

unionfind::~unionfind() {
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
