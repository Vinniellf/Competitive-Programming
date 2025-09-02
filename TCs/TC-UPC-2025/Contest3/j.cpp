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
    vector<vector<ll>> vec(n, vector<ll>(3)), ans(n, vector<ll>(2, 0));
    rep(i, 3) {
        rep(j, n) {
            cin >> vec[j][i];
        }
    } 

    if(n == 1) {
        cout << vec[0][0];
        return;
    }
    ans[1][1] = vec[0][1];
    ans[1][0] = vec[0][0];
    for(int i = 2; i < n; i++) {
        ans[i][1] = max(ans[i - 1][1] + vec[i - 1][1], ans[i - 1][0] + vec[i - 1][2]);
        ans[i][0] = max(ans[i - 1][1] + vec[i - 1][0], ans[i - 1][0] + vec[i - 1][1]);
    }

    cout << max(ans[n - 1][1] + vec[n - 1][0], ans[n - 1][0] + vec[n - 1][1]);
    

}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}