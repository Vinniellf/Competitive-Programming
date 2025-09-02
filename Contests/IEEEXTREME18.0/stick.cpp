#include<bits/stdc++.h>
using namespace std;

//Manera clasica de calcular combinatoria

typedef long long ll;
const ll MOD = 998244353;
const string ga = "infinity";

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n, k, l; cin>>n>>k>>l;
    if(k >= 2*l){
        cout<<n * 4 * l * l;
    } else {
        ll res = 2 * l - k;
        res = res * res;
        res = 4 * l * l - res;
        ll sum = 4 * l * l;
        sum += res * (n - 1);
        cout<<sum;
    }

    return 0;
}