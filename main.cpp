#include <iostream>
#include <vector>
#include "graph.h"
#include "unionfind.h"
#include <time.h>

using namespace std;

int main() {
    clock_t startTime, endTime;

//    string mediumG = "../test_data/mediumDG.txt";
//
//    cout << "=====use benchmark=====\n";
//    cout << "reading graph from " << mediumG << '\n';
//    graph mg(mediumG);
//    cout << "adjacency list created\n";
//    cout << "bridges: \n";
//    startTime = clock();
//    list<int *> mbridge = mg.benchmark();
//    endTime = clock();
//    cout << "time spent: " << (double) (endTime - startTime) << "ms\n";
//    mg.destroy_bridge(mbridge);
//
//    cout << "=====use union find tarjan lca=====\n";
//    unionfind ufm(mediumG);
//    startTime = clock();
//    ufm.tarjan_lca();
//    endTime = clock();
//    cout << "time spent: " << (double) (endTime - startTime) << "ms\n";
//    cout << "bridges: \n";
//    ufm.print_bridge();
//
//
//    cout << "\n=====LARGE=====\n";
//    string largeG = "../test_data/largeG.txt";
//    cout << "reading graph from " << largeG << '\n';
//    unionfind ufl(largeG);
//    cout << "read graph complete\n";
//    startTime = clock();
//    ufl.tarjan_lca();
//    endTime = clock();
//    cout << "time spent: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s\n";
//    ufl.print_bridge();

    cout << "=====random graph=====\n";
    double ave_time;
    for (int i = 1; i < 11; ++i) {
        for (int j = 1; j < 11; ++j) {
            ave_time = 0;
            for (int k = 0; k < 20; ++k) {
                unionfind uf(i * 1000000, (i + j) * 1000000);
                startTime = clock();
                uf.tarjan_lca();
                endTime = clock();
                ave_time += (double) (endTime - startTime) / CLOCKS_PER_SEC;
            }
            cout << i << ", " << i + j << ", " << ave_time / 20 << "\n";
        }
    }

    return 0;
}