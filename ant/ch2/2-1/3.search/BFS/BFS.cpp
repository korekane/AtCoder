#include <cstdio>
#include <queue>
using namespace std;

const int INF = 1000000;

typedef pair <int,int> P;

//入力
#define MAX_N 100
#define MAX_M 100
char maze[MAX_N][MAX_M+1] = {
    {'#','S','#','#','#','#','#','#','.','#'},
    {'.','.','.','.','.','.','#','.','.','#'},
    {'.','#','.','#','#','.','#','#','.','#'},
    {'.','#','.','.','.','.','.','.','.','.'},
    {'#','#','.','#','#','.','#','#','#','#'},
    {'.','.','.','.','#','.','.','.','.','#'},
    {'.','#','#','#','#','#','#','#','.','#'},
    {'.','.','.','.','#','.','.','.','.','.'},
    {'.','#','#','#','#','.','#','#','#','.'},
    {'.','.','.','.','#','.','.','.','G','#'}
    };
int N=10,M=10;
int sx = 0,sy = 1; //スタートの座標
int gx = 9,gy = 8; //ゴールの座標

int d[MAX_N][MAX_M]; //各店までの最短距離の配列

//移動4方向のベクトル
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

//{sx,sy}から{gx,gy}への最短距離を求める．
//たどりつけないときはINF
int bfs(){
    queue<P> que;
    //すべての点をINFで初期化
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            d[i][j] = INF;
        }
    }

    //スタート地点をqueueに挿入し，その点の距離を0とする．
    que.push(P(sx,sy));
    d[sx][sy]=0;

    //queueが空になるまでループ
    while(que.size()){
        //queueの先頭を取り出す
        P p = que.front();
        que.pop();
        //取り出した状態がゴールであれば探索終了
        if (p.first == gx&& p.second == gy) break;
        //4方向をループ
        for (int i =0;i<4;i++){
            //i=1なら→へ
            //i=2なら↓へ
            //i=3なら←へ
            //i=4なら↑へ
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            
            //移動が可能かの判定とすでに訪れたことがあるかの判定
            //(d[nx][ny] != INF なら訪れたことがある)
            if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF){
                que.push(P(nx,ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}

void solve(){
    int res = bfs();
    printf("%d",res);
}

int main(){
    solve();
    return 0;
}