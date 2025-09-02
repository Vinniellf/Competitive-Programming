#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 2e5 + 5;
vector<vector<int>> grafo(MAXN);
int coun[MAXN];

void dfs(int node, int parent) {
    coun[node] = 1;
    for(auto u: grafo[node]) {
        if(u != parent) {
            dfs(u, node);
            coun[node] += coun[u];
        }
    }
}

void solve() {
    int n; cin >> n;
    for(int i = 2; i <= n; i++) {
        int a; cin >> a;
        grafo[i].push_back(a);
        grafo[a].push_back(i);
    }

    dfs(1, 0);

    for(int i = 1; i <= n; i++) {
        cout << coun[i] - 1 << " ";
    }



}



signed main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}