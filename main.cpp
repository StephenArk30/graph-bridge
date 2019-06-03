#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

int main() {
//    string mediumG = "../test_data/mediumDG.txt";
    string largeG = "../test_data/largeG.txt";
//    graph g(mediumG);
//    vector<int *> bridge = g.benchmark();
//    g.destroy_bridge(bridge);
    cout << "reading graph from " << largeG << '\n';
    graph g(largeG);
    cout << "adjacency list created\n";
    vector<int *> bridge = g.benchmark();
    g.destroy_bridge(bridge);

    return 0;
}