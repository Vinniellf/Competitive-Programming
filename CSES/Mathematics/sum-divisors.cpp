#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll N = 1e6;

ll mulmod(ll a, ll b){
    return ((a % MOD) * (b % MOD)) % MOD;
}

int main(){
    ll n; cin>>n;
    ll ans = (n % 2 == 0 ? mulmod(n / 2, n + 1) : mulmod(n, (n + 1)/2));
    for(ll i = 1LL; i * i <= n; i++){
        ans = (ans + mulmod(i, (n - i) / i)) % MOD;
    }
    cout<<ans;
}