//
// Created by Stephen Ark on 5/31/2019.
//

#ifndef GRAPH_BRIDGE_GRAPH_H
#define GRAPH_BRIDGE_GRAPH_H

#include <string>
#include <vector>

using namespace std;

class graph {
private:
    vector<int> *adj_list;
    int v_num, e_num;
    string data_file;
public:
    graph(string &filename);
};


#endif //GRAPH_BRIDGE_GRAPH_H
