#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;
#define MAX_N 100

int main(){
    //宣言
    priority_queue<int> pque;
    
    //要素の追加
    pque.push(3);
    pque.push(5);
    pque.push(1);

    //空になるまでループ
    while(!pque.empty()){
        //最大値の取得および削除
        printf("%d\n",pque.top());
        pque.pop();
    }
    return 0;
}