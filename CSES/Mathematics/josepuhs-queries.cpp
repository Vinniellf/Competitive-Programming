#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll N = 1e6;

void solve(){
    int k, n; cin>>n>>k;
    if(n == 1) {cout<<1<<"\n"; return;}
    int N = n;
    bool par = true;
    int factor = 1;
    int frst = 1;
    for(int i = 0; i <= 65; i++){
        if(frst + (par ? factor : 0) + 2*factor*(k - 1) <= N) {cout<<frst + (par ? factor : 0) + 2*factor*(k - 1)<<"\n"; return;}
        int res = (par? n/2 : (n + 1)/2);
        if(!par) frst += factor;
        if(n % 2 == 1) par = (par ^ 1);
        k -= res; n -= res;
        factor *= 2;
    }
    
    
}

int main(){
    int q; cin>>q;
    while(q--){
        solve();
    }
}