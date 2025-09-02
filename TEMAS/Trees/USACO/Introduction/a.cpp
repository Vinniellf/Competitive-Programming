#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5 + 5;


void solve() {
    int a, b; cin >> a >> b;
    int c, d; cin >> c >> d;

    c -= a; d -= b;
    int x = min(a, b), y = min(c, d);

    if(x < (b + a)/3 || y < (d + c)/3) {
        cout <<"NO" << endl;
    } else cout << "YES\n";

    
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