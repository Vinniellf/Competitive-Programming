#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5 + 5;

vector<vector<int>> grafo(MAXN);
int v[MAXN];
int a;
int ans = 0;

void dfs(int node, int d) {
    if(v[node] == -1) {
        v[node] = d + 1;
        if(v[node] > ans) {ans = v[node]; a = node;}
    }
    for(auto x: grafo[node]) {
        if(v[x] != -1) continue;
        dfs(x, d + 1);
    }
}

void solve() {
    int n; cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    memset(v, -1, sizeof(v));
    dfs(0, -1);
    //cout << a << " " << ans << endl;
    memset(v, -1, sizeof(v));
    dfs(a, -1);
    cout << ans;

    
}



signed main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}