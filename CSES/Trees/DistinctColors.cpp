#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back

vector<vector<int>> g;
vector<int> c, ans, touch;
vector<map<int, int>> m;

void dfs(int u, int p = -1) {
    touch[u] = 1;
    for(int v: g[u]) {
        if(!touch[v] && v != p) {
            dfs(v, u);
            if(m[u].size() < m[v].size()) m[u].swap(m[v]);
            for(auto a : m[v]) m[u].insert(a);
        }
    }

    ans[u] = m[u].size();
}

void solve() {
    int n; cin >> n;
    g.resize(n);
    ans.assign(n, 0);
    touch.assign(n, 0);
    m.resize(n);

    for(int i = 0; i < n; i++) {
        int c; cin >> c;
        m[i].insert({c, 1});
    }

    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);
    for(int col: ans) cout << col << " ";
    cout << endl;
    return;
}

int main(){
    #ifndef ONLINE_JUDGE 
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif
    fastio;
    solve();

    return 0;
}