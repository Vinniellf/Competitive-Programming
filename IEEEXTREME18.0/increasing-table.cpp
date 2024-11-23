#include<bits/stdc++.h>
using namespace std;

//Manera clasica de calcular combinatoria

typedef long long ll;
const ll MOD = 998244353;
const int N = 2000;
ll dp[2*N + 1][2*N + 1];

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, x, y, in; cin>>n;
    vector<int> suma(2*n + 1, 0), resta(2*n + 1, 0);
    cin>>x;
    for(int i = 0; i < x; i++){cin>>in; suma[in]++;}
    cin>>y;
    for(int i = 0; i < y; i++){cin>>in; resta[in]++;}
    for(int i = 1; i <= 2*n; i++){
        if(suma[i] > 1 || resta[i] > 1) {cout<<00; return 0;}
    }

    //caso base
    if(resta[1] == 0) dp[1][1] = 1;
    else {cout<<000 ; return 0;}
    for(int i = 2; i <= 2*n; i++){
        for(int j = 0; j <= 2*n; j++){
            if(suma[i]){
                if(j - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                continue;
            }
            if(resta[i]){
                if(j + 1 <= 2*N) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
                continue;
            }
            if(j - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            if(j + 1 <= 2*N) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;

        }
    }

    cout<<dp[n*2][0];
    return 0;
}