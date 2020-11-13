#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

//トポロジカルソートの実装
//トポロジカルソートする
vector<bool> seen;
vector<int> order; //トポロジカルソート順を表す
void rec(const Graph &G, int v){
    seen[v] = true;
    for(auto next_v : G[v]){
        if(seen[next_v]) continue; //既に訪問済みならば探索しない
        rec(G, next_v);
    }

    //v-outを記録する
    order.push_back(v);
}

int main(){
    int N, M;
    cin >> N >> M; //頂点数と枝数
    Graph G(N);  //頂点数Nのグラフ
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    //探索
    seen.assign(N, false); //初期状態では全頂点が未訪問
    order.clear();  //トポロジカルソート順  
    for(int v = 0; v < N; v++){
        if(seen[v]) continue;  //既に訪問済ならば探索しない
        rec(G, v);
    }
    reverse(order.begin(), order.end());  //逆順

    //出力
    for(auto v : order){
        cout << v << "->";
    }
    cout << endl;
    return 0;
}