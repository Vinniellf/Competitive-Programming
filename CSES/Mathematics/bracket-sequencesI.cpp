#include<bits/stdc++.h>
using namespace std;

//Manera clasica de calcular combinatoria

typedef long long ll;
const ll MOD = 1e9 + 7;
const int N = 1e6;
ll factorial[N + 1];


ll powMod(ll num, ll exp){
    ll res = 1LL;
    while(exp > 0){
        if(exp % 2 == 1) res = (res * num) % MOD;
        exp /= 2;
        num = (num * num) % MOD;
    }
    return res;
}

ll mul(ll x, ll y) {return ((x % MOD) * (y % MOD)) % MOD;}
ll inv(ll num) {return powMod(num, MOD - 2);}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n; cin>>n;
    if(1 & n) {cout<<0; return 0;}
    for(int i = 0; i <= N; i++) factorial[i] = 1LL;
    for(int i = 1; i <= N; i++) factorial[i] = (i * factorial[i - 1]) % MOD;
    
    cout<<mul(factorial[n], mul(inv(factorial[n/2]), inv(factorial[n/2 + 1])));
    return 0;
}