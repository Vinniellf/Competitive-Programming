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

const ll MOD = 998244353LL;
const int INF = 1e9;

void solve(){
    ll x, m; cin>>x>>m;
    ll ans = 0;

    if(m >= x){
        ll p = (m/x  - 1) * x;
        ans += m/x  - 1;
        p += x;
        if((p ^ x) <= m) ans++;
        p += x;
        if((p ^ x) <= m) ans++;
    }
    


    for(ll y = 1LL; y <= min(x, m); y++){
        ll ga = (y ^ x);
        if(ga % x == 0 || ga % y == 0){
            ans++;
        }
    }

    if(x <= m) ans--;
    cout<<ans<<endl;
}

int main(){

    fastio;
    cases{
        solve();
    }

    return 0;
}