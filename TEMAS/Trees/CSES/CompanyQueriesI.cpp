#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5 + 5;

vector<vector<int>> grafo(MAXN);
int p[25][MAXN], parent[MAXN];
int n; 

void dfs(int node, int p = -1) {
    parent[node] = p;
    for(auto x: grafo[node]) {
        if(p == x) continue;
        dfs(x, node);
    }
}

void pre() {
    for(int i = 0; i < 25; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0) {p[i][j] = parent[j]; continue;}
            int ga = p[i - 1][j];
            if(ga == -1) p[i][j] = -1;
            else p[i][j] = p[i - 1][ga];
        }
    }

}


int query(int a, int b) {
    for(int i = 0; i < 25; i++) {
        if((1 << i) & b) a = p[i][a];
        if(a == -1) return -1;
    }

    return a + 1;
}


void solve() {
    int q;
    cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int a; cin >> a;
        a--; 
        grafo[a].push_back(i);
        grafo[i].push_back(a);
    }

    dfs(0);
    memset(p, -1, sizeof(p));
    pre();


    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        a--;
        cout << query(a, b) << endl;
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