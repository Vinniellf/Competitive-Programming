#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll MOD = 1000003;
//const ll MOD2 = 911382323;
const ll p1 = 71, p2 = 97;
const ll maxN = 1e18;
 
int mostSignificantBitIndex(unsigned int n) {
    if (n == 0) return -1; 
    return 31 - __builtin_clz(n); 
}
 
void solve(){
    int n; cin>>n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin>>vec[i];
    }
 
    int mx = vec[0];
 
    for(int i = 1; i < n; i++) mx &= vec[i];
    int bit = 50;
    for(int i = 0; i < n; i++){
        bit = min(bit, mostSignificantBitIndex(vec[i]));
    }

    if(bit == -1) {cout<<mx; return;}
    //cout<<bit<<" "<<mx<<endl;
 
    for(int i = 0; i < n; i++){
        if((vec[i] & (1LL<<bit)) == 0) vec[i] = (1<<mostSignificantBitIndex(vec[i])) - 1 - vec[i];
    }
 
    int ans = vec[0];
 
    for(int i = 1; i < n; i++) ans &= vec[i];
 
    cout<<max(ans, mx);
    
 
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    while(t--){solve();}
    return 0;
}