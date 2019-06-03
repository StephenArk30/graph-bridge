//
// Created by Stephen Ark on 5/31/2019.
//

#ifndef GRAPH_BRIDGE_GRAPH_H
#define GRAPH_BRIDGE_GRAPH_H

#include <string>
#include <list>

using namespace std;

class graph {
private:
    list<int> *adj_list;
    int v_num, e_num;
    string data_file;

    int *bfs(int s, int *color);

    int get_next_start(const int *color);
    void print_bridge(vector<int *>bridge);
public:
    explicit graph(string &filename);

    ~graph();

    int get_connected_num();

    vector<int *> benchmark(); // 基准算法
    void destroy_bridge(vector<int *>bridge);
};


#endif //GRAPH_BRIDGE_GRAPH_H
