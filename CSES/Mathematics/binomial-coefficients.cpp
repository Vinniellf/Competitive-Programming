#include<bits/stdc++.h>
using namespace std;

//Manera clasica de calcular combinatoria

typedef long long ll;
const ll MOD = 1e9 + 7;
const int N = 1e6;
ll factorial[N + 1];

ll powMod(ll num, ll exp, ll m){
    ll res = 1LL;
    while(exp > 0){
        if(exp % 2 == 1) res = (res * num) % m;
        exp /= 2;
        num = (num * num) % m;
    }
    return res;
}

ll mulMod(ll x, ll y) {return ((x % MOD) * (y % MOD)) % MOD;}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n; cin>>n;
    ll a, b;

    for(int i = 0; i <= N; i++) factorial[i] = 1LL;
    for(int i = 1; i <= N; i++) factorial[i] = (i * factorial[i - 1]) % MOD;
    for(int i = 0; i < n; i++){
        cin>>a>>b;
        cout<<mulMod(factorial[a], mulMod(powMod(factorial[b], MOD - 2, MOD), powMod(factorial[a - b], MOD - 2, MOD)));
        cout<<"\n";
    }
}