#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, x; cin>>n>>x;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin>>vec[i];
    int mn = 1e9 + 9;
    int index;
    for(int i = 0; i < n; i++){
        if(vec[i] < mn){mn = vec[i]; index = i;}
    }
    if(vec[index] < x) vec[index] = x;
    ll suma = 1LL;
    ll ans = 0LL;
    for(int i = 0; i < n; i++){
        ll suma = 1LL;
        for(int l = i - 1; l >= 0; l--){
            if(vec[l] >= vec[i]) suma++;
            else break;
        }
        for(int r = i + 1; r < n; r++){
            if(vec[r] >= vec[i]) suma++;
            else break;
        }
        ans = max(ans, suma*vec[i]);
    }
    cout<<ans;
    return 0;
}