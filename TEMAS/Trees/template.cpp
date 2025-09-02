#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define REP(i,k,n) for (int i = k; i <n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define PI 3.14159265359
#define F first
#define S second
#define int long long

typedef long double ld;

vector<vector<int>> grafo(MAXN);

void solve() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    
}



signed main() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}