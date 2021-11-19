#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;

//入力
int N = 6;
char S[MAX_N] = {"ACDBCB"};

void solve(){
    //S[a],S[a+1],...,S[b]が残っている文字列
    int a=0;
    int b=N-1;

    while(a<=b){
        //左から見た場合と右から見た場合を比較
        bool left =false;
        for (int i = 0; a+1<=b;i++){
            if(S[a+i]<S[b-i]){
                left =true;
                break;
            }
            else if (S[a+i]>S[b-i]){
                left=false;
                break;
            }
        }
        if (left) {
            putchar(S[a++]);
        }
        else{
            putchar(S[b--]);
        }
    }
    putchar('\n');
}

int main(){
    solve();
    return 0;
}