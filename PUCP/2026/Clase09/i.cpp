#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define all(v) v.begin(), v.end()
#define int long long

int n;
bool ok(int num) {
    int c = 0;
    for(int i = 1; i <= min(n, num); i++) {
        c += min(num / i, n);
    }

    return c >= ((n * n) / 2 + 1);
}

void solve() {
    cin >> n;
    int l = 0, r = 1e13;
    while(r - l > 1) {
        int mid = (r + l) / 2;
        if(ok(mid)) r = mid;
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
    while(t--) solve();

    return 0;
}