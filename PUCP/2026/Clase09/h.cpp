#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define int long long
#define all(v) v.begin(), v.end()

int n, k;

bool ok(int mx, vector<int> &v) {
    int c = 0;
    int curr = 0;
    rep(i, n) {
        if((curr + v[i]) > mx) {
            c++;
            curr = v[i];
            continue;
        }
        curr += v[i];
    }
    c++;
    return c > k;
}

void solve() {
    cin >> n >> k;
    vector<int> v(n);
    rep(i, n) cin >> v[i];

    int l = *max_element(all(v)) - 1, r = 1e15;
    while(r - l > 1){ 
        int m = (r + l) / 2;
        if(ok(m, v)) l = m;
        else r = m;
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