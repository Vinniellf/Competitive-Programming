#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve(){
    ll a, b, c; cin>>a>>b>>c;
    cout<<binpow(a, binpow(b, c, MOD - 1), MOD)<<"\n";
}

signed main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
}