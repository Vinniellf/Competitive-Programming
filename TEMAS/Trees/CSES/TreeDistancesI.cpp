#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5 + 5;

vector<vector<int>> grafo(MAXN);
vector<pair<int, int>> maxLen1(MAXN, {0, -1});
vector<int> maxLen2(MAXN);
int maxParent1[MAXN];

int dfs1(int node, int p = -1) {
    for(auto x: grafo[node]) {
        if(x == p) continue;
        int ga = 1 + dfs1(x, node);
        if(ga >= maxLen2[node]) {
            if(ga > maxLen1[node].first) {
                maxLen2[node] = maxLen1[node].first;
                maxLen1[node].first = ga;
                maxLen1[node].second = x;
            } else maxLen2[node] = ga;
        }
    }
    return maxLen1[node].first;
}

void dfs2(int node, int p = -1, int road = -1) {
    if(p == -1) maxParent1[node] = 0;
    else {
        if(node == road)  maxParent1[node] = 1 + max(maxParent1[p], maxLen2[p]);
        else maxParent1[node] = 1 + max(maxParent1[p], maxLen1[p].first);
    }
    for(auto x: grafo[node]) {
        if(x == p) continue;
        dfs2(x, node, maxLen1[node].second);
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

    int uwu = dfs1(0);
    dfs2(0);

    for(int i = 0; i < n; i++) {
        cout << max(maxLen1[i].first, maxParent1[i]) << " ";
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