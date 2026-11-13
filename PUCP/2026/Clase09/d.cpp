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

    sort(all(v));
    int ans = 0;
    rep(i, n) {
        for(int j = i + 1; j < n; j++) {
            int r = v[i] + v[j];
            int l = abs(v[i] - v[j]);
            auto itr = lower_bound(all(v), r);
            auto itl = upper_bound(all(v), l);
            int c = distance(itl, itr);
            if(v[i] > l && v[i] < r) c--;
            if(v[j] > l && v[j] < r) c--;
            ans += c;
        }
    }
    cout << ans / 3 << endl;
}
// 1 2 3 4
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