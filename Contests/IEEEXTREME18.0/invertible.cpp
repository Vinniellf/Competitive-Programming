#include<bits/stdc++.h>
using namespace std;

//principio de inclusion y exclusion

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll N = 1e18;

void solve(){
    int n, a, b; cin>>n;
    vector<bool> compuerta(n/2 + 2, false);
    vector<int> vec(n + 4, 0);
    for(int i = 2; i < n + 2; i += 2){
        cin>>vec[i]>>vec[i + 1];
        if(vec[i] * vec[i + 1] < 0) compuerta[i/2] = true;
    }
    compuerta[0] = true; compuerta [n/2 + 1] = true;
    vector<int> ans;
    for(int i = 0; i < n/2 + 2; i++){
        if(compuerta[i]) ans.push_back(i);
    }
    ll res = 0LL;
    ll nores = 0LL;
    for(int i = 0; i < n/2 + 2; i++){
        res = max(res + abs(vec[2*i + 1] + vec[i*2]), (ll)abs(vec[2*i + 1]));
        if(i == n/2) res = max(res + abs(vec[i*2]), (ll)abs(vec[2*i + 1]));
    }
    for(int i = n/2 + 1; i >=0 ; i--){
        nores = max(nores + abs(vec[2*i + 1] + vec[i*2]), (ll)abs(vec[2*i]));
        if(i == 1) nores = max(nores + abs(vec[i*2 + 1]), (ll)abs(vec[2*i]));
    }
    cout<<max(res, nores)<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}