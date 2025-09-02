#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5 + 5;

vector<vector<int>> grafo(MAXN);
vector<int> d(MAXN, 0);
vector<double> p(MAXN, 1);

void dfs(int node, int parent = -1) {
    double c = grafo[node].size() - (parent == -1 ? 0 : 1);
    for(auto x: grafo[node]) {
        if(x == parent) continue;
        d[x] = d[node] + 1;
        p[x] = p[node] / c;
        dfs(x, node);
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

    dfs(0);
    double ans = 0.0;
    for(int i = 1; i < n; i++) {
        if(grafo[i].size() == 1) {
            ans += (double)d[i] * p[i];
        }
    }
 
    cout << fixed << setprecision(10) << ans;

    
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