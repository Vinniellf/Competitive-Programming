#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5 + 5;

int suma(int num) {
    string s = to_string(num);
    int ans = 0;
    for(int i = 0; i < s.size(); i++) ans += s[i] - '0';
    return ans;
}


void solve() {
    int n; cin >> n;
    int ans = 0;
    for(int i = 0; i <= n; i++){
        ans += suma(i);
    } 
    cout << ans << endl;
}



signed main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}