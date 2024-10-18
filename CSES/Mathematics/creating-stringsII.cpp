#include<bits/stdc++.h>
using namespace std;

//Manera clasica de calcular combinatoria

typedef long long ll;
const ll MOD = 1e9 + 7;
const int N = 1e6;
ll factorial[N + 1];
ll cant[26];

ll powMod(ll num, ll exp, ll m){
    ll res = 1LL;
    while(exp > 0){
        if(exp % 2 == 1) res = (res * num) % m;
        exp /= 2;
        num = (num * num) % m;
    }
    return res;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s; cin>>s;
    for(int i = 0; i < 26; i++) cant[i] = 0LL;
    for(int i = 0; i < s.size(); i++) cant[s[i] - 'a']++;

    for(int i = 0; i <= N; i++) factorial[i] = 1LL;
    for(int i = 1; i <= N; i++) factorial[i] = (i * factorial[i - 1]) % MOD;
    ll res = factorial[s.size()];
    for(int i = 0; i < 26; i++){
        res = (res * powMod(factorial[cant[i]], MOD - 2, MOD)) % MOD;
    }
    cout<<res;
}