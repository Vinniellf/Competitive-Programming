#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5 + 5;

vector<vector<int>> grafo(MAXN);
int c[MAXN], d[MAXN];
int ans[MAXN];
int suma = 0;
int n; 

void dfs1(int node, int p = -1) {
    for(auto x: grafo[node]) {
        if(x == p) continue;
        d[x] = d[node] + 1;
        suma += d[x];
        dfs1(x, node);
        c[node] += c[x] + 1;
    }
}

void dfs2(int node, int p = -1, int s = suma) {
    ans[node] = s;
    for(auto x: grafo[node]) {
        if(x == p) continue;
        dfs2(x, node, s + n - 2 - 2 * c[x]);    
    }
}

void solve() {
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    dfs1(0);
    dfs2(0);

    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }


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