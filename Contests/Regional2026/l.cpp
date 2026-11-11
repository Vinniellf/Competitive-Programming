#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back


vector<int> to, d, active;
vector<vector<int>> g;
vector<map<int, int>> m;
int mn = 1e9 + 5;
int ans = 0;

void pre_dfs(int u, int p = -1, int c = 0) {
    d[u] = c;
    for(int v: g[u]) {
        if(v != p) pre_dfs(v, u, c+1);
    }
    return;
}

void dfs(int u, int p = -1) {
    for(int v: g[u]) {
        if(v == p) continue;
        dfs(v, u);
        if(m[u].size() < m[v].size()) m[v].swap(m[u]);

        if((int)m[v].size() == 0) continue;
        auto itv = m[v].begin();
        int av = itv->first;
        int bv = itv->second;

        auto itu = m[u].begin();
        int au = itu->first;
        int bu = itu->second;

        int target = au + av - 2 * d[u];
        if(target < mn) {
            mn = target;
            ans = bu * bv;
        } else if(target == mn) {
            ans += bu * bv;
        }

        for(auto [a, b]: m[v]) {
            m[u][a] += b;
        }

    }
    return;
}

void solve() {
    int n; cin >> n;
    to.resize(n);
    d.resize(n, 0);
    g.resize(n);
    active.resize(n, 0);
    m.resize(n);

    rep(i, n) cin >> active[i];
    rep(i, n - 1){  
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    pre_dfs(0);
    rep(i, n) {
        if(active[i] == 1) m[i].insert({d[i], 1});
    }
    dfs(0);

    cout << mn << " " << ans << endl;
}

signed main(){
    #ifndef ONLINE_JUDGE 
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif
    fastio;
    solve();

    return 0;
}