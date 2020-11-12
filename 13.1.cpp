#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

//グラフ探索の実装(幅優先探索)
//グラフGにおいて、頂点sを始点とした探索を行う
void search(const Graph &G, int s){
    int N = (int)G.size();  //グラフの頂点数

    //グラフ探索の為のデータ構造
    vector<bool> seen(N, false);
    queue<int> todo;  //空の状態(深さ優先探索の場合は stack<int>)

    //初期条件
    seen[s] = true;  //sは探索済
    todo.push(s);  //todoはsのみを含む状態となる

    //todoが空になるまで探索を行う
    while (!todo.empty())
    {
        //todoから頂点を取り出す
        int v = todo.front();
        todo.pop();

        //vから辿れる頂点を全て調べる
        for(int x : G[v]){
            //既に発見済の頂点は探索しない
            if(seen[x]) continue;

            //新たな頂点xを探索済にしてtodoに挿入
            seen[x] = true;
            todo.push(x);
        }
    }
    
}