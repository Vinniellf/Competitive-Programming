#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define int long long
#define all(v) v.begin(), v.end()

int k, x; 

bool ok(int num) {
    int acum = 0;
    if(num <= k) {
        acum += (num * (num + 1)) / 2;
        return acum >= x;
    }
    acum += (k * (k + 1)) / 2;
    int cant = num - k;
    int fi = k - 1;
    int la = fi - cant + 1;
    acum += ((fi + la) * cant) / 2;
    return acum >= x;
}

void solve() {
    cin >> k >> x;

    int l = 0, r = 2 * k - 1;
    while(r - l > 1) {
        int m = (r+l) / 2;
        if(ok(m)) r = m;
        else l = m;
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
    cin >> t;
    while(t--) solve();

    return 0;
}