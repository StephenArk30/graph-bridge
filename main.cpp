#include <iostream>
#include <vector>
#include "graph.h"
#include "unionfind1.h"
#include "unionfind2.h"

using namespace std;

int main() {
    string mediumG = "../test_data/mediumDG.txt";

    cout << "=====use benchmark=====\n";
    cout << "reading graph from " << mediumG << '\n';
    graph mg(mediumG);
    cout << "adjacency list created\n";
    list<int *> mbridge = mg.benchmark();
    mg.destroy_bridge(mbridge);

    /*cout << "=====use union find force find=====\n";
    unionfind1 uf1(mediumG);
    uf1.benchmark(mg);
    uf1.printBridge();*/

    cout << "=====use union find tarjan lca=====\n";
    unionfind2 uf2(mediumG);
    uf2.tarjan_lca();
    uf2.print_bridge();


    /*string largeG = "../test_data/largeG.txt";
    cout << "reading graph from " << largeG << '\n';
    graph lg(largeG);
    cout << "adjacency list created\n";
    list<int *> lbridge = lg.benchmark();
    lg.destroy_bridge(lbridge);*/

    return 0;
}