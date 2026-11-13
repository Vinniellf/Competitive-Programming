#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define int long long

int t;
bool ok(int k, vector<int> &v) {
    int c = 0;
    rep(i, (int)v.size()) {
        c += (k / v[i]);
        if(c >= t) return true;
    }

    return false;
}

void solve() {
    int n; cin >> n >> t;
    vector<int> v(n);
    rep(i, n) cin >> v[i];

    int l = 0, r = 1e18 + 5;

    while(r - l > 1) {
        int mid = (r+l)/2;
        if(ok(mid, v)) r = mid;
        else l = mid; 
    }

    cout << r << endl;

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