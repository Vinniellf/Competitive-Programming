#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 100000000000031;
const string ga = "infinity";

ll modLargeNumber(const string& num, ll mod) {
    ll remainder = 0LL;

    for (char digit : num) {
        remainder = (remainder * 10 + (digit - '0')) % mod;
    }

    return remainder;
}

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int suma(const string& num){
    int suma = 0;
    for (char digit : num) {
        suma = (suma + (digit - '0'));
    }
    return suma;

}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string numero; cin>>numero;
    if(suma(numero) % 9 != 0) {cout<<-1; return 0;}
    ll res = modLargeNumber(numero, MOD);
    int ceros = numero.size() - 1;
    int x = 22*((ceros)/21);
    x += (ceros) % 21;
    x = 2 * x;
    ll ans = binpow(3, x, MOD);
    for(int i = 1; i <= 20; i++){
        if(res == ans) {cout<<x; return 0;}
        ans = (ans * 3) % MOD;
        x++;
    }
    cout<<-1;
    return 0;
}