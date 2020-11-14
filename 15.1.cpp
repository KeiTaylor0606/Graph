#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

//クラスカル法の実装

struct Edge
{
    int to;  //隣接頂点番号
    ll w; //重み
    Edge(int to, ll w) : to(to), w(w) {}
};

//Union-Find
struct UnionFind{
    vector<int> par, siz;
    //par:各頂点の親頂点の番号を表す。自信が根の場合は-1
    //siz:各頂点の属する根付き木の頂点数を表す

    //初期化
    UnionFind(int n) : par(n, -1), siz(n, 1) { }

    //根を求める
    int root(int x){
        if(par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    //xとyが同じグループに属するかどうか(根が一致するかどうか)
    bool issame(int x, int y){
        return root(x) == root(y);
    }

    //xを含むグループとyを含むグループとを併合する
    bool unite(int x, int y){
        //x,yをそれぞれ根まで移動する
        x = root(x);
        y = root(y);

        //既に同じグループの時は何もしない
        if(x == y) return false;

        //unite by size(y側のサイズが小さくなる様にする)
        if(siz[x] < siz[y]) swap(x, y);

        //yをxの子とする
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x){
        return siz[root(x)];
    }
};

//辺 e = (u, v)を{w(e), {u, v}}で表す
using Edge = pair<int , pair<int, int>>;

int main(){
    //入力
    int N, M; //頂点数と辺数
    cin >> N >> M;
    vector<Edge> edges(M); //辺集合
    for(int i = 0; i < M; i++){
        int u, v, w; //wは重み
        cin >> u >> v >> w;
        edges[i] = Edge(w, make_pair(u, v));
    }

    //各辺を、辺の重みが小さい順にソートする
    //pairはデフォルトで(第一要素、第二要素)の辞書順比較
    sort(edges.begin(), edges.end());

    //クラスカル法
    ll res = 0;
    UnionFind uf(N);
    for(int i = 0; i < M; i++){
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        //辺(u, v)の追加によってサイクルが形成されるときは追加しない
        if(uf.issame(u, v)) continue;

        //辺(u, v)を追加する
        res += w;
        uf.unite(u, v);
    }
    cout << res << endl;
    return 0;
}