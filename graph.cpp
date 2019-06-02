//
// Created by Stephen Ark on 5/31/2019.
//

#include <fstream>
#include "graph.h"

// create adjacency list
graph::graph(string &filename) : data_file(filename) {
    ifstream file;
    file.open(data_file);
    file >> v_num >> e_num;
    adj_list = new vector<int>[v_num];
    int temp_node1, temp_node2;
    for (int i = 0; i < v_num; ++i) {
        file >> temp_node1 >> temp_node2;
        adj_list[temp_node1].push_back(temp_node2);
        adj_list[temp_node2].push_back(temp_node1);
    }
}
