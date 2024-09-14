#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

const int MOD = 1e9 + 7;
const int N = 2e5 + 1;

void solve(){
    int n; cin>>n;
    if(n%4 != 0 and (n + 1)%4 != 0) {cout<<0; return;}
    vector<int> vec(n);
    vector<vector<int>> dp(2, vector<int>(N, 0));
    for(int i = 0; i < n; i++) vec[i] = i + 1;
    dp[0][0] = 1; dp[1][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= N; j++){
            if(dp[0][j]){
                dp[1][j + vec[i]] = (dp[1][j + vec[i]] + dp[0][j])%MOD;
            }
        }
        for(int j = 0; j <= N; j++) dp[0][j] = dp[1][j];
    }
    int ans = dp[1][(n*(n + 1))/4];
    int res = ans % 2;
    cout<<(res == 0? ans/2 : (MOD + ans)/2);
    return;
    
}

int main(){
    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}