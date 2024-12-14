#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define cases ll T=0;cin>>T;while(T--)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define REP(i,k,n) for (int i = k; i <n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define PI 3.14159265359

typedef long double ld;
typedef long long ll;

const ll MOD = 998244353LL;
const int INF = 1e9 + 5;
const int maxN = 1e6;
int n, t[4 * maxN];

void build(int a[], int v, int tl, int tr){
    if(tl == tr){
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }
}

int query(int v, int tl, int tr, int l, int r){
    if(l > r) return INF;
    if(l == tl && r == tr) return t[v];
    int tm = (tl + tr) / 2;
    return min(query(v * 2, tl, tm, l, min(tm, r)), query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int v, int tl, int tr, int pos, int new_val){
    if(tl == tr){
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if(pos <= tm){
            update(v * 2, tl, tm, pos, new_val);
        } else {
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        }
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }

}

int main(){
    fastio;
    for(int i = 0; i < 4 * maxN; i++) t[i] = INF;
    int q; cin>>n>>q;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    build(a, 1, 0, n - 1);
    
    for(int i = 0; i < q; i++){
        int k, a, b; cin>>k>>a>>b;
        if(k == 1){
            update(1, 0, n - 1, a - 1, b);
        } else {
            cout<<query(1, 0, n - 1, a - 1, b - 1)<<endl;
        }
    }
    return 0;
}