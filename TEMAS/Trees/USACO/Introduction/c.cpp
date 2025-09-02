#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5 + 5;

void solve() {
    int n; cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];

    vector<vector<int>> v(n + 1);
    vector<int> dp(n + 1, 0);
    int curr = 0;
    for(int i = 0; i < n; i++) {
        dp[i + 1] = curr;
        v[vec[i]].push_back(i + 1);
        int l = v[vec[i]].size();
        if(l >= vec[i]) {
            int in = v[vec[i]][l - vec[i]] - 1;
            dp[i + 1] = max(dp[i + 1], dp[in] + vec[i]);
            curr = dp[i + 1];
        }
        
    }

    cout << dp[n] << endl;
}



signed main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}