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


void solve() {
    int n; cin >> n;
    vector<int> vec(n);
    rep(i, n) cin >> vec[i];
    int ans = 0;
    rep(i, n - 1) {
        if(vec[i] < vec[i + 1]) ans++;
    }
    if(ans > 1) cout << ans - 1 << endl;
    else cout << ans << endl;
    

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