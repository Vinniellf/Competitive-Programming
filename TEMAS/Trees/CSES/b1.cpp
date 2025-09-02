#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5 + 5;

vector<int> d;

void init() {
    int a = 1;
    for(int i = 0; i < 18; i++) {
        a *= 10;
        d.push_back(a + 1);
    }
}

void solve() {
    int n; cin >> n;
    vector<int> ans;
    for(int i = 0; i < d.size(); i++) {
        if(n % d[i] == 0) ans.push_back(n / d[i]);
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    if(ans.size() != 0) cout << endl;    
}



signed main() {
    int t = 1;
    cin >> t;
    init();
    while(t--) {
        solve();
    }
}