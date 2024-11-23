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

void init(){
    pow1[0] = pow2[0] = 1;
    h1[0] = h2[0] = (int) (S[0] - 'a' + 1);
    for(int i = 1; i < maxN; i++){
        int c = (int) (S[i] - 'a' + 1);
        pow1[i] = (pow1[i-1] * p1) % MOD;
        pow2[i] = (pow2[i-1] * p2) % MOD;
        pow_inv1[i] = binpow(pow1[i], MOD - 2, MOD);
        pow_inv2[i] = binpow(pow2[i], MOD - 2, MOD);
        h1[i] = (h1[i-1] + c * pow1[i]) % MOD;
        h2[i] = (h2[i-1] + c * pow2[i]) % MOD;
    }
}

int main(){
    scanf(" %s", S);
    N = (int) strlen(S);
    init();
}