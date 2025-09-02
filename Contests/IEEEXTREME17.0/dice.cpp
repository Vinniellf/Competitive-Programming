#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const string ENDL = "\n";
const ll MOD = 998244353;

ll binpow(ll num, ll exp){
    num = num % MOD;
    ll ans = 1LL;
    for(int i = 0; i <= 63; i++){
        if((exp & (1LL << i))) ans = (ans * num) % MOD;
        num = (num * num)%MOD;
    }
    return ans;
}

int main(){
    cout<< (7 * binpow(108, MOD - 2))%MOD;
    
    
    
}