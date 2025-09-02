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

const ll MOD = 1e9 + 7;
const int INF = 1e9;
const int MAXN = 1e6 + 5;

ll factorial[MAXN];
ll p2[MAXN];

void init() {
    factorial[0] = 1;
    p2[0] = 1;
    for(int i = 1; i < MAXN; i++){ 
        p2[i] = (2 * p2[i - 1]) % MOD;
        factorial[i] = (factorial[i - 1] * i) % MOD;
    } 
}

void solve() {
    init();
    ll n; cin >> n;
    cout << (factorial[n] - p2[n - 1] + MOD) % MOD;
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