#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 9;
const int p = 31;

signed main(){
    string s; cin>>s;
    int n = s.size();
    vector<long long> nor(s.size()), rev(s.size());
    long long hash_value = 0LL;
    long long power = 1LL;
    for(int i = 0; i < n; i++){
        hash_value = (hash_value + (s[i] - 'a' + 1) * power) % MOD;
        nor[i] = hash_value;
        power = (power * p) % MOD;
    }
    hash_value = 0LL;
    for(int i = n - 1; i >= 0; i--){
        hash_value = (hash_value * p + (s[i] - 'a' + 1)) % MOD;
        rev[i] = hash_value;
    }

    for(int i = 0; i < n - 1; i++){
        if(nor[i] == rev[n - 1 - i]) cout<<i + 1<<" ";
    }

    
}