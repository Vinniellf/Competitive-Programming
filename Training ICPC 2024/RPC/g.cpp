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
typedef long long int ll;
const int maxN = 1e5 + 7;
ll dp[505][maxN];
const ll mod = 1e9 + 7;

void solve(){
    int n; cin>>n;
    string s; cin>>s;

    dp[0][0] = 1;
    int k;

    for (int i = 0; i < n; i++) {
        if(s[i] == '#') continue;
        for(int j = 0; j < 500; j++){
            dp[j][i + 1] += dp[j][i];
            dp[j][i + 1] %= mod;

            k = (i + j + 2 >= n) ? n : (i + j + 2);
            dp[j + 1][k] += dp[j][i];
            dp[j + 1][k] %= mod;
        }
    }

    ll ans = 0LL;
    for(int i = 0; i < 500; i++){
        ans += dp[i][n];
        ans %= mod;
    }
    cout<<ans;    
    
}

signed main(){
    fastio;
    solve();

    return 0;
}