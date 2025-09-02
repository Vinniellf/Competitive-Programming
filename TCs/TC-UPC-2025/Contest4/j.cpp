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
const int MAXN = 1e5 + 5;


void solve() {
    ll n; cin >> n;
    bitset<MAXN * 2> bi;
    vector<ll> p(MAXN, 0);
    ll ans = 0;
    bi[1] = 1;
    vector<ll> vec(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> vec[i];
        p[i] = p[i - 1] + vec[i];
    }

    for(int i = 1; i <= n; i++) {
        bi |= (bi << vec[i]);
        if(bi[i]) {
            ans = max(ans, p[i] + 1 - i); bi[i] = 0;
        }
    }

    for(int i = n + 1; i <= 2 * n; i++) {
        if(bi[i]) {
            ans = max(ans, p[n] + 1 - i); 
        }
    }
    cout << ans;
   


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