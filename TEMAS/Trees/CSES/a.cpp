#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve() {
    int n, c; cin >> n >> c;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];
    int ans = 0;
    int factor = 1;
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    for(int i = 0; i < n; i++) {
        if(vec[i] * factor > c) ans++;
        else factor *= 2;
    }

    cout << ans << endl;
    
}


signed main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}