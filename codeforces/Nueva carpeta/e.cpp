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
const int maxN = 1e6 + 5;

ll dp[maxN];
int main(){

    dp[2] = 1;
    vector<ll> p(maxN, 0);

    for(int i = 4; i < maxN; i++){
        p[i] = (i - 2)*(i - 1)/2 - 1 + (p[i - 1] * (i - 1) % MOD) % MOD;
    }

    for(int i = 3; i < maxN; i++){
        dp[i] = (((p[i - 1] * i) % MOD) + i - 1 + p[i]) % MOD;
    }
    fastio;
    cases{
        int n; cin>>n;
        cout<<dp[n]<<endl;
    }

    return 0;
}