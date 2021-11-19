#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;

#define MAX_V 100

struct vertex {
    vector<vertex*> edge;
    /*
    頂点の属性
    */
};
vertex G[MAX_V];

int main(){
    int V, E;
    printf("入力");
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++){
        //sからtへの辺をはる
        int s, t;
        scanf("%d %d", &s, &t);
        G[s].edge.push_back(&G[t]);
        //G[t].edge.push_back(&G[s]);
    }
    /*
    グラフの操作
    */
    return 0;
}