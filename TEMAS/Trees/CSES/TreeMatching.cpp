#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5 + 5;

vector<vector<int>> grafo(MAXN);
int dp[MAXN][2];

void reset() {
    for(int i = 0; i < MAXN; i++) {
        for(int j = 0; j < 2; j++){
            dp[i][j] = -1;
        }
    }

}

void dfs(int node, int p) {

    dp[node][0] = 0;
    for(auto x: grafo[node]) {
        if(x == p) continue;
        dfs(x, node);
        dp[node][0] += dp[x][1];
    }

    dp[node][1] = dp[node][0];
    for(auto x: grafo[node]) {
        if(x == p) continue;
        dp[node][1] = max(dp[node][1], dp[node][0] - dp[x][1] + dp[x][0] + 1);
    }

}

void solve() {
    reset();
    int n; cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    dfs(0, -1);
    cout << max(dp[0][1], dp[0][0]);

}



signed main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}