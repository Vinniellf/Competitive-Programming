#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const ll p1 = 53, p2 = 37;
const int maxN = 1e5+5;

int N;
char S[maxN];
ll pow1[maxN], h1[maxN];
ll pow_inv1[maxN];

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
    pow1[0] = pow_inv1[0] = 1;

    h1[0] = 0;
    for(int i = 1; i < maxN; i++){
        int c = (int) (S[i - 1] - 'A' + 1);
        pow1[i] = (pow1[i-1] * p1) % MOD;
        pow_inv1[i] = pow_inv1[i - 1] * k1 % MOD;
        h1[i] = (h1[i-1] + c * pow1[i - 1]) % MOD;
    }
}

ll hashing(string s){
    ll has = (int) (s[0] - 'A' + 1);
    for(int i = 1; i < s.size(); i++){
        int c = (int) (s[i] - 'A' + 1);
        has = (has + c * pow1[i]) % MOD;
    }
    return has;
}

int main(){
    scanf(" %s", S);
    N = (int) strlen(S);

    vector<vector<int>> alpha(52);
    for(int i = 0; i < N; i++){
        if(S[i] - 'a' >= 0) alpha[S[i] - 'a'].push_back(i + 1);
        else alpha[S[i] - 'A' + 26].push_back(i + 1);
    }
    init();

    int n; cin>>n;
    for(int i = 0; i < n; i++){
        string a; cin>>a;
        int len = a.size();
        ll has = hashing(a);
        int index = a[0] - 'a' >= 0 ? a[0] - 'a' : a[0] - 'A' + 26;
        bool ok = false;
        for(int j = 0; j < alpha[index].size(); j++){
            int l = alpha[index][j];
            if(len + l >= N) break;
            if((h1[len + l - 1] - h1[l - 1] + MOD) * pow_inv1[l - 1] % MOD == has) ok = true; break;
        }

        cout<< (ok ? "Y\n" : "N\n");
    }
}