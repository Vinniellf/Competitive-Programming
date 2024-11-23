#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const long long MOD = 1e9 + 9;
const int p = 31;
const int N = 1e6 + 1;
ll power[N];
ll power_inv[N];
ll hash[N];

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
    power[0] = 1;
    for(int i = 1; i <= N; i++) power[i] = (power[i - 1] * p) % MOD;
    for(int i = 0; i <= N; i++) power_inv[i] = binpow(power[i], MOD - 2, MOD);
}


long long resta(ll a, ll b) {return (a < b? a - b + MOD: a - b);}


signed main(){
    init();
    string s; cin>>s;
    int n = s.size();
    vector<long long> hash(n);
    hash[0] = (s[0] - 'a' + 1);
    for(int i = 1; i < n; i++) hash[i] = (hash[i - 1] + (s[i] - 'a' + 1) * power[i]) % MOD;
    vector<ll> ans;
    for(int i = 1; i <= n; i++){
        ll periodo = hash[i - 1];
        bool is_periodic = true;
        ll resto = n % i;
        if(resto > 0){
            if(hash[resto - 1] != (resta(hash[n - 1], hash[n - resto - 1]) * power_inv[n - resto]) % MOD){
                continue;
            }
        }
        for(int j = i; j + i - 1 < n; j += i){
            if(periodo != (resta(hash[j + i - 1], hash[j - 1]) * power_inv[j]) % MOD) {is_periodic = false; break;}
        }

        if(is_periodic) ans.push_back(i);
    }
    for(auto x: ans){
        cout<<x<<" ";
    }
}

//solucion optimizaba 
/*
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const ll p1 = 31, p2 = 37;
const int maxN = 1e6+5;
 
int N;
char S[maxN];
ll pow1[maxN], pow2[maxN], h1[maxN], h2[maxN];
 
void init(){
    pow1[0] = pow2[0] = 1;
    h1[0] = h2[0] = (int) (S[0] - 'a' + 1);
    for(int i = 1; i < maxN; i++){
        int c = (int) (S[i] - 'a' + 1);
        pow1[i] = (pow1[i-1] * p1) % MOD;
        pow2[i] = (pow2[i-1] * p2) % MOD;
        h1[i] = (h1[i-1] + c * pow1[i]) % MOD;
        h2[i] = (h2[i-1] + c * pow2[i]) % MOD;
    }
}
 
int main(){
    scanf(" %s", S);
    N = (int) strlen(S);
    init();
 
    for(int len = 1; len <= N; len++){
        ll hash1 = h1[len-1], hash2 = h2[len-1];
        for(int i = 0; i < (N/len)-1; i++){
            hash1 = (hash1 * pow1[len] + h1[len-1]) % MOD;
            hash2 = (hash2 * pow2[len] + h2[len-1]) % MOD;
        }
        hash1 = (hash1 + h1[N%len-1] * pow1[(N/len) * len]) % MOD;
        hash2 = (hash2 + h2[N%len-1] * pow2[(N/len) * len]) % MOD;
        if(hash1 == h1[N-1] && hash2 == h2[N-1])    printf("%d ", len);
    }
}*/