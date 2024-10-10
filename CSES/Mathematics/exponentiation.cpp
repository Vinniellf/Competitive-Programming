#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const string ENDL = "\n";

ll binpow(ll num, ll exp){
    if(exp == 0) return 1;
    num = num % MOD;
    ll ans = 1LL;
    for(int i = 0; i <= 63; i++){
        if(exp & (1LL << i)) ans = (ans * num) % MOD;
        num = (num * num) %MOD;
    }
    return ans;
}

int main(){
    int n; cin>>n;
    int a, b;
    while(n--){
        cin>>a>>b;
        cout<<binpow(a, b)<<ENDL;
    }
}