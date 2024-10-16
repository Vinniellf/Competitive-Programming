#include<bits/stdc++.h>
using namespace std;

//principio de inclusion y exclusion

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll N = 1e18;

int main(){
    ll n; int k; 
    cin>>n>>k;
    vector<ll> primes(k);
    for(int i = 0; i < k; i++) cin>>primes[i];
    ll ans = 0LL;
    for(int i = 1; i < (1<<k); i++){
        ll prod = 1LL;
        for(int j = 0; j < k; j++){
            if(i & (1<<j)) {
                if(primes[j] > n/prod) {prod = N + 1; break;}
                prod *= primes[j];
            }
        }
        ans += (__builtin_parity(i)? n/prod : (-1LL)*(n/prod));
    }
    cout<<ans<<"\n";
    return 0;
}