#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;

#define MAX_N 100
#define MAX_V 100



//頂点fromから頂点toへのコストcostの辺
struct edge{int from, to, cost;};


edge es[MAX_N];             //辺

int d[MAX_V];               //最短距離
int V, E;                   //V:頂点数，E:辺の数
int INF = 100000;

//s番目の頂点から各頂点への最短距離を求める
void shortest_path(int s){
    for (int i = 0; i < V; i++){
        d[i] = INF;
    }
    d[s] = 0;
    while(true){
        bool update = false;
        for (int i = 0; i < E; i++){
            edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if (!update) break;
    }
}

int main(){
    int s = 2;                  //s番目のノード
    shortest_path(s);
    return 0;
}