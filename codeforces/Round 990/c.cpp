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
const ll INF = 1e12;
bool ok[maxN];

void solve(){
    int n; cin>>n;
    vector<ll> vec1(n), vec2(n);
    for(int i = 0; i < n; i++) cin>>vec1[i];
    for(int i = 0; i < n; i++) cin>>vec2[i];

    ll mx = 0;
    for(int i = 0; i < n; i++) {
        mx += max(vec1[i], vec2[i]);
    }

    ll ans = -INF;
    for(int i = 0 ; i < n; i++){
        ans = max(ans, mx + min(vec1[i], vec2[i]));
    }

    cout<<ans<<endl;
    
    return;
}

signed main(){
    fastio;
    cases{
        solve();
    }

    return 0;
}