#include<bits/stdc++.h>
using namespace std;

//Manera clasica de calcular combinatoria

typedef long long ll;
const ll MOD = 998244353;
const string ga = "infinity";

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, q; cin>>n>>m;
    vector<int> vec(n + 1, 0);
    ll low, high; 
    for(int i = 0; i < m; i++){
        cin>>low>>high;
        cin>>q;
        for(int j = 0; j < q; j++){
            int in; cin>>in;
            vec[in]++;
        }
    }
    for(int i = 0; i < n; i++){
        if(vec[i] == 0) cout<<ga;
    }
    return 0;
}