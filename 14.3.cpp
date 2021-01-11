#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;
//using Graph = vector<vector<int>>;

//ダイクストラ方の実装

//無限大を表す値
const ll INF = 1LL << 60;

//辺を表す型
struct Edge{
    int to;
    ll w;
    Edge(int to, ll w) : to(to), w(w) {}
};

//重みつきグラフを表す型
using Graph = vector<vector<Edge>>;

//緩和を実施する関数
template<class T>bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    else {
        return false;
    }
}

int main(){
    //頂点数、辺数、始点
    int N, M ,s;
    cin >> N >> M >> s;

    //グラフ
    Graph(G);
    for(int i = 0; i < N; i++){
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }

    //ダイクストラ法
    vector<bool> used(N, false);
    vector<ll> dist(N, INF);
    dist[s] = 0;
    for(int iter = 0; iter < N; iter++){
        //「使用済み」でない頂点のうち、dist値が最小の頂点を探す
        ll min_dist = INF;
        int min_v = -1;
        for(int v = 0; v < N; v++){
            if(!used[v] && dist[v] < min_dist){
                min_dist = dist[v];
                min_v = v;
            }
        }

        //もしそのような頂点が見つからなければ終了
        if(min_v == -1){
            break;
        }

        //min_vを始点とした各辺を緩和する
        for(auto e : G[min_v]){
            chmin(dist[e.to], dist[min_v] + e.w);
        }
        used[min_v] = true; //min_vを「使用済み」とする
    }

    //結果出力
    for(int v = 0; v < N; v++){
        if(dist[v] < INF){
            cout << dist[v] << endl;
        }
        else{
            cout << "INF" << endl;
        }
    }

    return 0;
}