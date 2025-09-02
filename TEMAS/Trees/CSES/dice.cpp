#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAXD = 8388610;
const int MOD = 998244353;
int f[MAXD];
int inv_f[MAXD];
int n, k;

int modPow(int base, int exp, int mod) {
    int result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}



void solve() {
    cin >> n >> k;
    int ans = 0;
    f[0] = 1;
    inv_f[0] = 1;
    for(int i = 1; i <= n; i++) {
        f[i] = (f[i - 1] * i) % MOD;
        inv_f[i] = modPow(f[i], MOD - 2, MOD);
    }

    int ex = modPow(6, MOD - 2, MOD);
    int deno = 1;

    for(int i = 1; i <= k; i++) {
        deno = (deno * ex) % MOD;
        if(n < i) break;
        if(6 * i < n) continue;
        int ga = n;
        for(int t = 1; t <= 6; t++){
            if(ga - t * i <= 6 - t) {ga = ga - t * i; break;}
        }
        ans = (ans + (((f[ga - 1] * inv_f[i - 1] % MOD) * inv_f[ga - i] % MOD) * deno % MOD)) % MOD;
    }

    ans = (ans * modPow(k, MOD - 2, MOD)) % MOD;

    cout << ans << endl;
    
}



signed main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}