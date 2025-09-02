#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5 + 5;

vector<vector<int>> grafo(MAXN);

void solve() {
    int n, m; string a, b, c, ans; 
    cin >> n >> a ; cin >> m >> b; cin >> c;
    string p;
    ans = a;
    int l = 0, r = m - 1;
    for(int i = 0; i < m; i++) {
        if(c[i] == 'D') {
            ans += b[i];
        } else {
            p += b[i];
        }
    }

    reverse(p.begin(), p.end());
    cout << p << ans << endl;
    
}



signed main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}