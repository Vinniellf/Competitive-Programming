#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back

vector<vector<int>> g;
vector<int> c;
vector<map<int, int>> m;
vector<int> ans, par;

struct LCA {
    int LOG;
    vector<int> d;
    vector<vector<int>> up;

    LCA(const vector<vector<int>>& g, int r = 0)
        : LOG(__lg(g.size()) + 1), d(g.size()),
          up(LOG, vector<int>(g.size(), r)) {
        vector<int> q{r};
        for (int i = 0; i < (int)q.size(); ++i) {
            int v = q[i];
            for (int u : g[v]) if (u != up[0][v]) {
                d[u] = d[v] + 1;
                up[0][u] = v;
                for (int j = 1; j < LOG; ++j)
                    up[j][u] = up[j-1][up[j-1][u]];
                q.push_back(u);
            }
        }
    }

    int lca(int u, int v) {
        if (d[u] < d[v]) swap(u, v);
        for (int j = LOG - 1; j >= 0; --j)
            if ((d[u] - d[v]) >> j & 1) u = up[j][u];
        if (u == v) return u;
        for (int j = LOG - 1; j >= 0; --j)
            if (up[j][u] != up[j][v])
                u = up[j][u], v = up[j][v];
        return up[0][u];
    }

    int dist(int u, int v) {
        return d[u] + d[v] - 2 * d[lca(u, v)];
    }
};

int dfs(int u, int p = -1, int fre_nodes) {
    par[u] = p;
    bool ok = false;
    if((int)g[0].size() == 1 && p == -1) {
        return dfs(v, u, fre_nodes + 1);
    }
    else {
        int total = (int) m[0].size();
        for(int v: g[0]) {
            int fre_nodes = total - m[v].size();
            if(fre_nodes >= 0 && dfs(v, 0, fre_nodes)) {
                for(auto x: m[v])


                return true;
            }   
        }
    }
    return false;
}

void pre_dfs(int u, int p = -1) {
    for(int v: g[u]) {
        if(v == p) continue;
        stl(v, u);
        c[u] += c[v];
    }
}

void solve() {
    int n; cin >> n;
    g.resize(n);
    c.resize(n, 0);
    m.resize(n, 0);
    ans.resize(n, 0);
    par.resize(n, 0);

    rep(i, n - 1) {
        int p; cin >> p;
        p--;
        g[i].push_back(p);
        g[v].push_back(i);
    }

    // para tener la cantidad de pozos en un subarbol
    rep(i, n) if((int)g[i].size() == 1 && i != 0) c[i] = 1;
    pre_dfs(0);
    
    if(dfs(0, -1, 0)) for(int x: ans) cout << x << " ";
    else cout << "*";
    cout << endl;
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