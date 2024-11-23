#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
const ll MOD = 10000019;
const ll GA = 1e8;
const ll p1 = 43, p2 = 37;
const int maxN = 1e3+5;

int N;
char S[maxN];
ll pow1[maxN], pow2[maxN], h1[maxN], h2[maxN];
ll inv1[maxN], inv2[maxN];


ll binpow(ll num, ll exp){
    ll res = 1;
    while(exp > 0){
        if(exp % 2 == 1) res = (res * num) % MOD;
        num = (num * num) % MOD;
        exp /= 2;
    }
    return res; 
}

void init(){
    pow1[0] = pow2[0] = inv1[0] = inv2[0] = 1;
    for(int i = 1; i < maxN; i++){
        pow1[i] = (pow1[i-1] * p1) % MOD;
        pow2[i] = (pow2[i-1] * p2) % MOD;
        inv1[i] = binpow(pow1[i], MOD - 2);
        inv2[i] = binpow(pow2[i], MOD - 2);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    string a;
    while(getline(cin, a)){
        string s;
        if(a.empty()) break;
        //////////
        for(int i = 0; i < a.size(); i++) if(a[i] != ' ') s += a[i];
        N = s.size();

        h1[0] = h2[0] = 0;
        for(int i = 1; i <= N; i++){
            int c = (int) (s[i - 1] - 'A' + 1);
            h1[i] = (h1[i-1] + c * pow1[i - 1]) % MOD;
            h2[i] = (h2[i-1] + c * pow2[i - 1]) % MOD;
        }

        unordered_map<ll, int> m;
        vector<int> ans(N + 1);
        for(int len = 1; len <= N; len++){
            for(int i = 0; i + len <= N; i++){
                ll val1 = (h1[i + len] - h1[i] + MOD) * inv1[i] % MOD;
                ll val2 = (h2[i + len] - h2[i] + MOD) * inv2[i] % MOD;
                ll val = val1 * GA + val2;
                m[val]++; 
                ans[len] = max(ans[len], m[val]);
            }
            if(ans[len] == 1) break;
        }

        for(int i = 1; i <= N; i++){
            if(ans[i] == 1) {cout<<"\n"; break;}
            else cout<<ans[i];
            cout<<"\n";
        }
        
    }



}