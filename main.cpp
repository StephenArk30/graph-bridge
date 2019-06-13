#include <iostream>
#include <vector>
#include "graph.h"
#include "unionfind1.h"
#include "unionfind2.h"
#include <time.h>

using namespace std;

int main() {
    clock_t startTime, endTime;

    string mediumG = "../test_data/mediumDG.txt";

    cout << "=====use benchmark=====\n";
    cout << "reading graph from " << mediumG << '\n';
    graph mg(mediumG);
    cout << "adjacency list created\n";
    cout << "bridges: \n";
    startTime = clock();
    list<int *> mbridge = mg.benchmark();
    endTime = clock();
    cout << "time spent: " << (double) (endTime - startTime) << "ms\n";
    mg.destroy_bridge(mbridge);

    /*cout << "=====use union find force find=====\n";
    unionfind1 uf1(mediumG);
    uf1.benchmark(mg);
    uf1.printBridge();*/

    cout << "=====use union find tarjan lca=====\n";
    unionfind2 uf2m(mediumG);
    startTime = clock();
    uf2m.tarjan_lca();
    endTime = clock();
    cout << "time spent: " << (double) (endTime - startTime) << "ms\n";
    cout << "bridges: \n";
    uf2m.print_bridge();


    cout << "\n=====LARGE=====\n";
    string largeG = "../test_data/largeG.txt";
    cout << "reading graph from " << largeG << '\n';
    /*graph lg(largeG);
    cout << "adjacency list created\n";
    list<int *> lbridge = lg.benchmark();
    lg.destroy_bridge(lbridge);*/
    unionfind2 uf2l(largeG);
    cout << "read graph complete\n";
    startTime = clock();
    uf2l.tarjan_lca();
    endTime = clock();
    cout << "time spent: " << (double) (endTime - startTime) << "ms\n";
    uf2l.print_bridge();


    return 0;
}