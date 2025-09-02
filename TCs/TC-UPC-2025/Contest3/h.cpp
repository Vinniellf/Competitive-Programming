#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define PI 3.14159265359

typedef long double ld;
typedef long long ll;

const ll MOD = 998244353LL;
const int INF = 1e9;
const int MAXN = 1e6 + 5;

int vec[3][2];

void solve() {
    string s;
    getline(cin, s);
    rep(i, 3) cin >> vec[i][0] >> vec[i][1];
    bool ok = true;
    rep(i, 3) {
        if(vec[(i + 1) % 3][0] == vec[i][0] && vec[(i + 2) % 3][1] == vec[i][1]) ok = false;
        if(vec[(i + 2) % 3][0] == vec[i][0] && vec[(i + 1) % 3][1] == vec[i][1]) ok = false;
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";

}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}