#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define PI 3.14159265359

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

typedef tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_multiset;

const ll MOD = 998244353LL;
const int INF = 1e9;
const int MXN = 2e5 + 1;
vector<vector<int>> g;
int sz[MXN];
int n;

void size(int node, int p = -1) {
    sz[node] = 1;
    for(int u: g[node]) {
        if(u == p) continue;
        size(u, node);
        sz[node] += sz[u];
    }
}

int get_centroid(int node, int p = -1) {
    for(int u: g[node]) {
        if(u == p) continue;
        if(sz[u] > n / 2) return get_centroid(u, node);
    }
    return node;
}

void solve() {
    cin >> n;
    g.assign(n + 1, vector<int>());

    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    size(1);
    // cout << sz[1] << endl;
    cout << get_centroid(1) << endl;
}

int main(){
    #ifndef ONLINE_JUDGE 
        freopen("in.txt", "r", stdin);
    #endif
    fastio;
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}