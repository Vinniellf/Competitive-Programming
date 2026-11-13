#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define int long long
#define all(v) v.begin(), v.end()

void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    for(int i = 1; i < n; i++) {
        v[i] = v[i - 1] + v[i];
    }
    int ans = 0;
    rep(i, n) {
        int acum = 0;
        if(i > 0) acum += v[i - 1];
        int dr = upper_bound(all(v), k + acum) - v.begin(); 
        ans = max(ans, dr - i);
    }
    cout << ans << endl;
}

signed main(){
    #ifndef ONLINE_JUDGE 
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif
    fastio;
    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}