#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define int long long
#define all(v) v.begin(), v.end()

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];

    vector<vector<int>> idx(n + 1);
    rep(i, n) {
        idx[v[i]].push_back(i + 1);
    }


    int q; cin >> q;
    rep(i, q) {
        int l, r, x;
        cin >> l >> r >> x;
        auto itl = lower_bound(all(idx[x]), l);
        auto itr = upper_bound(all(idx[x]), r);
        cout << itr - itl << endl;
    }

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