#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

//s-tパスがあるかどうかを深さ優先探索を用いて判定する
//深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v){
    seen[v] = true; //vを訪問済にする
    
    //vからいける各頂点next_vについて
    for(auto next_v : G[v]){
        if(seen[next_v]) continue;  //next_vが探索済なら探索しない
        dfs(G, next_v);  //再帰的に検索
    }
}

int main(){
    //頂点と辺数、sとt
    int N, M, s, t;
    cin >> N >> M >> s >> t;

    //グラフ入力受け取り
    Graph G(N);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    //頂点sをスタートとした探索
    seen.assign(N, false); //全頂点を「未訪問」に初期化
    dfs(G, s);

    //tにたどり着けるかどうか
    if(seen[t]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}