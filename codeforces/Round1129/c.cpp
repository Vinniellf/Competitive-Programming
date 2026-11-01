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
vector<vector<int>> g;
vector<int> ok;
vector<int> touch;
vector<int> dist;

void dfs(int node, int d, bool pass_root) {
    touch[node] = 1;
    dist[node] = d;
    if(node == 0) pass_root = true;
    ok[node] = pass_root;
    for(int u: g[node]) {
        if(!touch[u]) {
            dfs(u, d + 1, pass_root);
        }
    }
    return;
}


void solve() {
    int n, m; cin >> n >> m;
    g.assign(n, vector<int>());
    ok.assign(n, 0);
    touch.assign(n, 0);
    dist.assign(n, 0);

    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(n - 1, 0, false);

    int ans = dist[0];
    rep(i, m) {
        int node; cin >> node;
        node--;
        if(!ok[node]) ans = max(ans, dist[node] + 1);
    }

    cout << ans << endl;
    return;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}