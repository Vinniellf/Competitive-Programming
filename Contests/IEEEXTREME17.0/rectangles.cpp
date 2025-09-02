#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const string ENDL = "\n";

vector<int> prime;
vector<int> vec;
vector<int> mask;
ll ans = 0LL;

void dp(int index, int bitmask) {
    if(index == vec.size()) return;
    if(mask[index] == 0) {ans += vec[index]; dp(index + 1, bitmask + mask[index]); return;}
    ll b = ans;
    if((bitmask & mask[index]) == 0) {ans += vec[index]; dp(index + 1, bitmask + mask[index]);}
    ll mx = ans;
    ans = b;
    dp(index + 1, bitmask);
    ans = max(ans, mx);
    return;
}

int main(){
    int r, l; cin>>r>>l;
    for(int i = r; i <= l; i++) vec.push_back(i);
    //primos del 1 al 100
    for(int i = 2; i <= 100; i++){
        bool is_prime = true;
        for(int j = 2; j*j <= i; j++){
            if(i % j == 0) {is_prime = false; break;}  
        }
        if(is_prime) prime.push_back(i);
    }
    for(int i = r; i <= l; i++){
        int m = 0;
        for(int j = 0; j < prime.size(); j++){
            if(i % prime[j] == 0) m += (1<<j);
        }
        mask.push_back(m);
    }
    dp(0, 0);
    cout<<ans;
    
}