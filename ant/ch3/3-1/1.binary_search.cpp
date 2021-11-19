#include <cstdio>
#define MAX_N 100

int n =5 ,k = 1;
int a[MAX_N] = {2,3,3,5,6};

void solve(){
    //解の存在範囲の初期化
    int lb = -1;
    int ub = n;

    //解の存在範囲が1より大きい間，繰り返す
    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (a[mid] >= k){
            // midが条件を満たせば，解の存在範囲は(lb, mid)
            ub = mid;
        } else{
            // midが条件を満たさなければ，解の存在範囲は(mid,ub)
            lb = mid;
        }
    }
    // この時点で，lb + 1 = ubとなっている
    printf("%d\n", ub);
}

int main(void){
    solve();
    return 0;
}