#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define cases ll T=0;cin>>T;while(T--)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define REP(i,k,n) for (int i = k; i <n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define PI 3.14159265359

typedef long double ld;
typedef long long ll;
const int maxN = 1e4;
const int INF = 1e9 + 5;
const ll MOD = 998244353LL;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n, q; cin>>n>>q;
    vector<int> a(n), b(n);
    rep(i, n) cin>>a[i];
    rep(i, n) cin>>b[i];
    
    vector<int> a_ord = a, b_ord = b;
    sort(all(a_ord)); sort(all(b_ord));

    ll ans = 1LL;
    rep(i, n){
        ans *= min(a_ord[i], b_ord[i]);
        ans %= MOD;
    }

    cout<<ans<<" ";

    rep(i, q){
        int o, j; cin>>o>>j;
        j--;
        if(o == 1){
            auto it = upper_bound(all(a_ord), a[j]);
            int in = it - a_ord.begin();
            in--;
            //cout<<"index "<<in<<endl;
            ans *= binpow(min(a_ord[in], b_ord[in]), MOD - 2, MOD);
            ans %= MOD;
            a_ord[in]++;
            ans *= min(a_ord[in], b_ord[in]);
            ans %= MOD;
            a[j]++;
        } else {
            auto it = upper_bound(all(b_ord), b[j]);
            int in = it - b_ord.begin();
            in--;
            //cout<<"index "<<in<<endl;
            ans *= binpow(min(a_ord[in], b_ord[in]), MOD - 2, MOD);
            ans %= MOD;
            b_ord[in]++;
            ans *= min(a_ord[in], b_ord[in]);
            ans %= MOD;
            b[j]++;
        }
        cout<<ans<<" ";

    }
    cout<<endl;
   
    return;
}

signed main(){
    fastio;
    cases{
        solve();
    }

    return 0;
}