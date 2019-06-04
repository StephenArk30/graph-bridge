#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

int main() {
    string mediumG = "../test_data/mediumDG.txt";

    cout << "reading graph from " << mediumG << '\n';
    graph mg(mediumG);
    cout << "adjacency list created\n";
    vector<int *> mbridge = mg.benchmark();
    mg.destroy_bridge(mbridge);

    string largeG = "../test_data/largeG.txt";
    cout << "reading graph from " << largeG << '\n';
    graph lg(largeG);
    cout << "adjacency list created\n";
    vector<int *> lbridge = lg.benchmark();
    lg.destroy_bridge(lbridge);

    return 0;
}