#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 911382323LL;
const ll p1 = 61, p2 = 97;
const int maxN = 1e6+5;
const int factor = 1e9;
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

ll hashing(string s){
    ll has = (int) (s[0] - 'a' + 1);
    ll has1 = (int) (s[0] - 'a' + 1);
    for(int i = 1; i < s.size(); i++){
        int c = (int) (s[i] - 'a' + 1);
        has = (has + c * pow1[i]) % MOD;
        has1 = (has1 + c * pow2[i]) % MOD;
    }
    return has +  factor * has1;
}


int main(){
    int n, k; cin>>n>>k;
    scanf(" %s", S);
    N = (int) strlen(S);
    init();

    unordered_map<ll, int> m; 
    int q; cin>>q;
    for(int i = 0; i < q; i++){
        string a; cin>>a;
        m[hashing(a)] = i + 1;
    }

    vector<int> ans;
    for(int i = 1; i <= k; i++){
        for(int j = i; j + k - 1 <= N; j += k){
            ll has = (h1[j + k - 1] - h1[j - 1] + MOD) * pow_inv1[j - 1] % MOD;
            ll has1 = (h2[j + k - 1] - h2[j - 1] + MOD) * pow_inv2[j - 1] % MOD;
            if(m[has + factor * has1] > 0) ans.push_back(m[has + factor * has1]);
            else {ans.clear(); break;} 
        }
       
        if(i != 1) {
            ll has = (h1[N] - h1[N - (k - i + 1)] + MOD) * pow_inv1[N - (k - i + 1)] % MOD;
            ll has1 = (h2[N] - h2[N - (k - i + 1)] + MOD) * pow_inv2[N - (k - i + 1)] % MOD;
            has = (has + h1[i - 1] * pow1[k - i + 1]) % MOD;
            has1 = (has1 + h2[i - 1] * pow2[k - i + 1]) % MOD;
            if(m[has + factor * has1] > 0) ans.push_back(m[has + factor * has1]);
        }

        if(ans.size() == n) {
            vector<int> lol = ans;
            sort(lol.begin(), lol.end());
            bool ok = true;
            for(int ga = 1; ga < n; ga++){
                if(lol[ga] == lol[ga - 1]) ok = false;
            }
            if(!ok) {ans.clear(); continue;}
            cout<<"YES\n";
            for(int i = 0; i < ans.size(); i++) cout<<ans[i]<<" ";
            return 0;
        }
        ans.clear();
    }

    cout<<"NO";
    return 0;
}