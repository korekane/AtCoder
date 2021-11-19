#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;
#define MAX_N 100

int heap[MAX_N], sz = 0;

void push(int x){
    //自分のノード番号
    int i = sz++;
    while(i>0){
        //親ノードの番号
        int p = (i-1)/2;
        //もう逆転していないなら抜ける
        if (heap[p]<=x)break;
        //親のノードの数字を下ろして自分は上に
        heap[i]=heap[p];
        i=p;
    }
    heap[i] = x;
}

int pop(){
    //最小値
    int ret = heap[0];

    //根に持ってくる値
    int x = heap[--sz];

    //根からおろしていく
    int i = 0;
    while(i*2+1<sz){
        //子同士を比較
        int a = i*2+1;
        int b = i*2+2;
        if (b < sz && heap[b] < heap[a]){
            a = b;
        }
        
        //逆転がなければ終わり
        if (heap[a] >= x) break;

        //子の数字を挙げる
        heap[i] = heap[a];
        i = a;
    }
    
    heap[i] = x;

    return ret;
}

int main(){
    //要素の追加
    push(10);
    push(20);
    push(100);
    push(1);
    for(int i =1;i<=4;i=i+1){
        int a = pop();
        printf("%d\n",a);
    }
}