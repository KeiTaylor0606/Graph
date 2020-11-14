#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

//緩和に用いる関数chmin
template<class T> bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    else return false;
}