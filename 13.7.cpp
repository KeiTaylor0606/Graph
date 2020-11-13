#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

//木上の探索
//v:現在探索中の頂点、p:vの親(vが根の時はp=-1)
void dfs(const Graph &G, int v, int p = -1){
    for(auto c : G[v]){
        if(c == p) continue; //探索が親方向へ逆流するのを防ぐ

        //cはvの各子頂点を動く。この時cの親はvとなる
        dfs(G, c, v);
    }
}