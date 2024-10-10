#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool ok(ll num){
    int cifra = (num % 10);
    num /= 10;
    while(num > 0){
        int new_cifra = (num % 10);
        if(cifra == new_cifra) return false;
        num /= 10;
    }
    return true;
}


int main(){
    ll a, b; cin>>a>>b;
    vector<vector<ll>> dp(19, vector<ll>(10, 0));
    //Inicializamos
    dp[0][0] = 1;
    for(int i = 1; i < 10; i++) dp[i][0] = dp[i - 1][0] + 1;
    cout<<dp[9][0];
    return 0;
}