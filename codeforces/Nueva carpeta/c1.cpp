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
    int ans = 0;
    for(ll i = 1LL; i <= min(x, m); i++){
        ll y = (i ^ x);
        if(x == y || y == 0LL || y > m) continue;
        if(x % i == 0 || y % i == 0) {ans++;}
    }
    cout<<ans<<endl;
}

int main(){

    fastio;
    cases{
        solve();
    }

    return 0;
}