#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

//根なし木を根付き木としたときの各頂点の深さを求める

vector<int> depth; //便宜上グローバルに答えを格納する

//d:頂点vの深さ(vが根の時はd = 0)
void dfs(const Graph &G, int v, int p = -1, int d = 0){
    depth[v] = d;
    for(auto c : G[v]){
        if(c == p) continue; //探索が親方向へ逆流するのを防ぐ
        dfs(G, c, v, d + 1); //dを1増やして子頂点へ
    }
}