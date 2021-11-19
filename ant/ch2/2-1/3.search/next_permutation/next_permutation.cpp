#include <cstdio>
#include <queue>
using namespace std;

#define MAX_N 100

bool used[MAX_N];
int perm[MAX_N];

void permutation1(int pos, int n){
    if (pos == n){
    /*permに対する操作*/
        return ;
    }
    //permのpos番目を0～n-1のどれにするかのループ
    for (int i = 0; i < n; i++){
        if (!used[i]){
            perm[pos] = i;
            //iを使ったのでフラグをtrueにしておく
            used[i] = true;
            permutation1(pos+1,n);
            //戻ってきたらフラグを立てておく
            used[i] = false;
        }
    }
    return;
}

#include <algorithm>

//重複があってもすべての順列を生成する
//next_permutationは辞書順で次の順列を生成する

int perm2[MAX_N];

void permutation2(int n){
    for (int i = 0; i < n; i++){
        perm2[i] = i;
    }
    do{
        /*perm2に対する操作*/
    }while(next_permutation(perm2, perm2 + n));
    return;
}

int main(){
    permutation2(10);
    return 0;
}