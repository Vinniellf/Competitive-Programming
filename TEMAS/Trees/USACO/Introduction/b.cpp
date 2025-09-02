#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5 + 5;


void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int l = 0, r = k - 1;
    int c = 0, u = 0;
    for(int i = 0; i <= r; i++){ 
        if(s[i] == '1') u++;
        else c++;
    }
    bool ok = true;
    if (c == 0) ok = false; // revisar primera ventana

    while (r + 1 < n) {
        if (s[l] == '1') u--; else c--;
        l++; r++;
        if (s[r] == '1') u++; else c++;
        if (c == 0) { ok = false; break; }
    }
    if(!ok) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        vector<int> ans(n);
        int a = n;
        for(int i = 0; i < n; i++){ 
            if(s[i] == '0') {
                ans[i] = a;
                a--;
            }
        }

        for(int i = 0; i < n; i++){ 
            if(s[i] == '1') {
                ans[i] = a;
                a--;
            }
        }

        for(int i = 0; i < n; i++){ 
            cout << ans[i] << " ";
        }
        cout << endl;

    }

    
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