#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const ll p1 = 31, p2 = 37;
const int maxN = 1e6+5;

int N;
char S[maxN];
ll pow1[maxN], pow2[maxN], h1[maxN], h2[maxN];
ll pow_inv1[maxN], pow_inv2[maxN];

ll binpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init(){
    ll k1 = binpow(p1, MOD - 2);
    ll k2 = binpow(p2, MOD - 2);
    pow1[0] = pow2[0] = pow_inv1[0] = pow_inv2[0] = 1;

    h1[0] = h2[0] = 0;
    for(int i = 1; i < maxN; i++){
        int c = (int) (S[i - 1] - 'a' + 1);
        pow1[i] = (pow1[i-1] * p1) % MOD;
        pow2[i] = (pow2[i-1] * p2) % MOD;
        pow_inv1[i] = pow_inv1[i - 1] * k1 % MOD;
        pow_inv2[i] = pow_inv2[i - 1] * k2 % MOD;
        h1[i] = (h1[i-1] + c * pow1[i - 1]) % MOD;
        h2[i] = (h2[i-1] + c * pow2[i - 1]) % MOD;
    }
}

int main(){
    scanf(" %s", S);
    N = (int) strlen(S);
    init();
    vector<int> ans;

    for(int len = 1; len <= N; len++){
        ll factor = h1[len];
        bool ok = true;
        for(int i = len; i <= N; i += len){
            if(factor == ((h1[i] - h1[i - len] + MOD) % MOD) * pow_inv1[i - len] % MOD) continue;
            ok = false;
            break;
        }

        if(h1[N % len] != ((h1[N] - h1[N - (N % len)] + MOD) % MOD) * pow_inv1[N - (N % len)] % MOD) ok = false;
        if(ok) ans.push_back(len);

    }

    for(int i = 0; i < ans.size(); i++) cout<<ans[i]<<" ";
}