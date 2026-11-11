/*
Esta versión está hecha con la técnica de Small To Large
*/
#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define int long long

vector<vector<int>> g;
vector<int> touch;
vector<map<int, int>> m;
vector<int> d;
int k;
int ans = 0;

void pre_dfs(int u, int p = -1, int c = 0) {
    d[u] = c;
    touch[u] = 1;
    for(int v: g[u]){
        if(!touch[v] && v != p) {
            pre_dfs(v, u, c + 1);
        }
    }
}

void dfs(int u, int p = -1) {
    touch[u] = 1;
    for(int v: g[u]) {
        if(!touch[v] && v != p) {
            dfs(v, u);
            if(m[u].size() < m[v].size()) {
                m[u].swap(m[v]);
            }

            for(auto [a, b]: m[v]) {
                int target = k - a + 2 * d[u];
                if(m[u].count(target)) {
                    ans += b * m[u][target];
                }
                // cout << u <<  " debug: " << target << " " << ans << " " << b << " " << m[u][target];
                // cout << endl;
            }

            for(auto [a, b]: m[v]) {
                m[u][a] += b;
            }
        }
    }
    // cout << "nodo: " << u << " ans: " << ans << endl;
}

void solve() {
    int n; cin >> n >> k;
    g.resize(n);
    touch.assign(n, 0);
    m.resize(n);
    d.resize(n, 0);

    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    pre_dfs(0);
    for(int i = 0; i < n; i++) m[i].insert({d[i], 1});
    touch.assign(n, 0);
    dfs(0);
    cout << ans << endl;
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