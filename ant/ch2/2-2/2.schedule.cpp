#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;

//入力
int N = 5;
int S[MAX_N] = {1,2,4,6,8};
int T[MAX_N] = {3,5,7,9,10};

//仕事をソートするためのpairの配列
pair<int, int> itv[MAX_N];

void solve(){
    //pairは辞書順で比較される
    //終了時間の早い順にしたいため，Tをfirstに，Sをsecondに入れる
    for (int i = 0; i < N; i++){
        itv[i].first = T[i];
        itv[i].second = S[i];
    }
    sort(itv, itv+N);

    int ans =0;
    int t = 0;
    for (int i=0;i<N;i++){
        if (t<itv[i].second){
            ans++;
            t = itv[i].first;
        }
    }

    printf("%d\n",ans);
}

int main(){
    solve();
    return 0;
}