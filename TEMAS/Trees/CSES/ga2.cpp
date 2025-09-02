#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve() {
    int n; cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];
    int mn = 1e12;
    bool ok = true;
    for(int i = 0; i < n; i++) {
        int ga = (2 * mn - 1 < 0? 0 : 2 * mn - 1);
        if(vec[i] > 2 * mn - 1) ok = false;
        mn = min(mn, vec[i]);
    }

    if(ok) cout << "YES\n";
    else cout << "NO\n";

    
}



signed main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}