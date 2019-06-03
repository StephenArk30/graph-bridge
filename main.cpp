#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

int main() {
    string mediumG = "../test_data/mediumDG.txt";
    graph g(mediumG);
    vector<int *> bridge = g.benchmark();
    g.destroy_bridge(bridge);

    return 0;
}