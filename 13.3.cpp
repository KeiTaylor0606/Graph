#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

//幅優先探索の基本形
//入力:グラフGと、探索の始点s
//出力:sから各頂点への最短路長を表す配列
vector<int> BFS(const Graph &G, int s){
    int N = (int)G.size(); //頂点数
    vector<int> dist(N, -1);  //前頂点を「未訪問」に初期化
    queue<int> que;

    //初期条件(頂点0を初期頂点とする)
    dist[0] = 0;
    que.push(0);


    //BFS開始(キューが空になるまで探索を行う)
    while (!que.empty())
    {
        int v = que.front(); //キューから先頭頂点を取り出す
        que.pop();

        //vから辿れる頂点を全て調べる
        for(int x : G[v]){
            //既に探索済みの頂点は探索しない
            if(dist[x] != -1) continue;

            //新たな白点頂点xについて距離情報を更新してキューに挿入
            dist[x] = dist[x] + 1;
            que.push(x);
        }
    }
    return dist;
}

int main(){
    //頂点数と辺数
    int N, M;
    cin >> N >> M;

    //グラフ入力受け取り(ここでは無向グラフを想定)
    Graph G(N);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(a);
        G[b].push_back(b);
    }

    //頂点0を始点としたBFS
    vector<int> dist = BFS(G, 0);

    //結果出力(各頂点の頂点0からの距離を求める)
    for(int v = 0; v < N; v++){
        cout << v << ": " << dist[v] << endl;
    }
    
    return 0;
}