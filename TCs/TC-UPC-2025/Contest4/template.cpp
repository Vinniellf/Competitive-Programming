#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define PI 3.14159265359

typedef long double ld;
typedef long long ll;

const ll MOD = 998244353LL;
const int INF = 1e9;
const int MAXN = 1e6 + 5;


void solve() {
    

}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}


ll pow(ll x, ll y, ll m) { // iterativo
    ll ret = 1;
    while (y) {
        if (y & 1) ret = (ret * x) % m;
        y >>= 1;
        x = (x * x) % m;
    }
    return ret;
}

// Encuentra mayor divisor primo
 // Un numero es primo si divi[x] == x
 // fact factoriza un número <= lim
 // La factorización sale ordenada
 //
 // crivo-O(n log(log(n)))
 // fact-O(log(n))
int divi[MAX];
void crivo(int lim) {
    for (int i = 1; i <= lim; i++) divi[i] = 1;
    for (int i = 2; i <= lim; i++) if (divi[i] == 1)
        for (int j = i; j <= lim; j += i) divi[j] = i;
}

//La función fact añadirá 1 al vector si intentas
//factorizar específicamente el número 1
void fact(vector<int>& v, int n) {
    if (n != divi[n]) fact(v, n/divi[n]);
        v.push_back(divi[n]);
}

