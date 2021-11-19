#include <cstdio>
#define MAX_N 100

int a[MAX_N]={1,2,4,7};
int n = 4, k = 15;

bool dfs(int i, int sum){
    if (i == n) return sum == k;
    if (dfs(i + 1, sum)) return true;
    if(dfs(i+1, sum + a[i])) return true;
    return false;
}

void solve(){
    if (dfs(0,0)) printf("YES\n");
    else printf("NO\n");
}

int main(){
    solve();
    return 0;
}