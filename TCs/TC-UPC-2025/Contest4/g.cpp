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

const ll MOD = 1e9 + 9;
const int INF = 1e9;
const int MAXN = 1e5 + 5;

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return (((res * res) % MOD) * a) % MOD;
    else
        return (res * res) % MOD;
}

ll op(ll num, ll k) {
    ll a1 = binpow(num + 1, k);
    ll a2 = binpow(num - 1, k);
    ll a3 = (2 * binpow(num, k)) % MOD;
    return (a1 - a3 + a2 + MOD) % MOD;
}


void solve() {
    ll k; cin >> k;
    ll mcd, mcm; cin >> mcd >> mcm;
    if(mcm % mcd != 0) {
        cout << 0;
        return;
    }
    mcm /= mcd;
    vector<int> ans;
    for(int i = 2; i * i <= mcm; i++) {
        int c = 0;
        while(mcm % i == 0) {
            c++;
            mcm /= i;
        }
        if(c != 0) ans.push_back(c);
    }
    if (mcm > 1) ans.push_back(1);

    ll total = 1;
    rep(i, ans.size()) {
        total = (total * op(ans[i], k)) % MOD;
    }
    cout << total;
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