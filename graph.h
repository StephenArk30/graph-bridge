//
// Created by Stephen Ark on 5/31/2019.
//

#ifndef GRAPH_BRIDGE_GRAPH_H
#define GRAPH_BRIDGE_GRAPH_H

#include <string>
#include <list>

using namespace std;

class graph {
    friend class unionfind;
private:
    list<int> *adj_list;
    int v_num, e_num;
    string data_file;

    void bfs(int s, int *color);

    int get_next_start(const int *color);

    void print_bridge(list<int *> bridge);
public:
    explicit graph(string &filename);

    ~graph();

    int get_connected_num();

    list<int *> benchmark(); // 基准算法
    void destroy_bridge(list<int *> bridge);
};


#endif //GRAPH_BRIDGE_GRAPH_H
