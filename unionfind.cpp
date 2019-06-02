//
// Created by Stephen Ark on 5/31/2019.
//

#include "unionfind.h"

unionfind::unionfind() {
    sets.clear();
}

void unionfind::makeset(int x) {
    node *temp_node = new node{
        x, nullptr, nullptr
    };
    set *temp_set = new set {
        temp_node, temp_node
    };
    temp_node->head = temp_set;
    sets.push_back(temp_set);
}

set *unionfind::findset(node *x) {
    return x->head;
}

bool unionfind::unionset(node *x, node *y) {
    set *set1 = findset(x);
    set *set2 = findset(y);
    if (set1 == nullptr || set2 == nullptr)
        return false;
    (set1->tail)->next = set2->head;
    set2->head = set1->head;
    set1->tail = set2->tail;
    return true;
}

unionfind::~unionfind() {
    vector<set *>::iterator iter;
    for (iter = sets.begin(); iter != sets.end(); iter++) {
        node *nd, *next = nullptr;
        for (nd = (*iter)->head; nd->next != nullptr; nd = next) {
            next = nd->next;
            delete (nd);
        }
        delete (*iter);
    }
}
