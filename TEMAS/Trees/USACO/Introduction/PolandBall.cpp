#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5 + 5;

vector<vector<int>> grafo(MAXN);
vector<int> v(MAXN, -1);
int ans = 0;

void dfs(int node, int p = -1){
    v[node] = 1;
    for(auto x: grafo[node]) {
        if(v[x] == 1) continue;
        dfs(x);
    }
}

void solve() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        a--;
        grafo[a].push_back(i);
        grafo[i].push_back(a);
    }

    for(int i = 0; i < n; i++) {
        if(v[i] == 1) continue;
        ans++;
        dfs(i);
    }

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