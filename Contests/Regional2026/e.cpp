#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back

vector<vector<int>> g;
vector<int> c;
vector<map<int, int>> m;
vector<int> ans, par;


void dfs(int u, int p) {
    for(auto v: g[u]) {
        if(v == p) continue;
        dfs(v, u);
        if(m[u].size() < m[v].size()) m[u].swap(m[v]);
        for(auto x: m[v]) m[u].insert(x);
    }
    if((int)m[u].size() > 1) {
        ans[m[u].begin()->first] = u + 1;
        m[u].erase(m[u].begin());
    }
}

void solve() {
    int n; cin >> n;
    g.resize(n);
    m.resize(n);
    ans.resize(n, 0);

    for(int i = 1; i < n; i++) {
        int p; cin >> p;
        p--;
        g[i].push_back(p);
        g[p].push_back(i);
    }

    rep(i, n) {
        if((int)g[i].size() == 1 && i != 0) m[i].insert({i, 1});
    }

    for(int v: g[0]) {
        dfs(v, 0);
        if(m[0].size() < m[v].size()) {
            m[0].swap(m[v]);
        }
        for(auto x: m[v]) m[0].insert(x);
    }

    // for(auto [a, b]: m[0]) cout << a << " " << b << endl;
    if((int)m[0].size() == 1) {
        ans[m[0].begin()->first] = 1;
    } else {
        cout << "*" << endl;
        return;
    }

    for(int x: ans) cout << x << " ";
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