#include<bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e12;

void solve() {
    int n; cin >> n;
    vector<int> vec(n), dp(n + 2, 0), ans(n), p(n);
    dp[0] = INF; 
    for(int i = 0; i <= n + 1; i++) dp[i] = -INF;

    int c = 0, m = 0;
    for(int i = 0; i < n; i++) {
        cin >> vec[i]; 
        int l = 0, r = n + 1;
        for(int j = 0; j < 100; j++) {
            int mid = (r + l) / 2;
            if(vec[i] >= dp[mid]) r = mid;
            else l = mid;
        }   
        if(dp[r] == -INF) c++;
        ans[i] = c;
        m += c;
        p[i] = m;
        dp[r] = vec[i];
    }

    int d = ans[0];
    int ga = 0;
    for(int i = 1; i < n; i++) {
        if(ans[i] != ans[i - 1]) {
            ga++;
        } 
        m += p[n - 1] - p[i - 1] - (n - i) * ga;
    }

    cout << m << endl;



}



signed main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}