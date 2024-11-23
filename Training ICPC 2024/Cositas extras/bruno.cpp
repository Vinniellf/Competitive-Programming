#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma")

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll MOD = 1e9 + 7;


const int maxM = 100;
const int maxL = 1e5 + 5;


int main(){
    fastio;
    int n, m, l; cin>>n>>l>>m;
    vector<vector<ll>> dp(l, vector<ll>(m, 0));
   vector<int>  mid(n), out(n);
   vector<int> count(m, 0), final(m, 0);
   int a;
   for(int i = 0; i < n; i++) {
    cin>>a;
    dp[0][a % m]++;
   }
   for(int i = 0; i < n; i++) {cin>>mid[i]; count[mid[i] % m]++;}
   for(int i = 0; i < n; i++) {cin>>a; final[(mid[i] + a) % m]++;}



   for(int i = 1; i < l; i++){
    for(int j = 0; j < m; j++){
        for(int k = 0; k < m; k++){
            if(dp[i - 1][j] == 0) break;
            if(i == l - 1){
                if(final[k] == 0) continue;
                dp[i][(j + k) % m] += (dp[i - 1][j] * final[k]) % MOD;
                dp[i][(j + k) % m] %= MOD;
            } else {
                if(count[k] == 0) continue;
                dp[i][(j + k) % m] += (dp[i - 1][j] * count[k]) % MOD;
                dp[i][(j + k) % m] %= MOD;
            }
        }
    }
   }

    cout<<dp[l - 1][0];

    return 0;
}
