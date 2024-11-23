#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1000003;
//const ll MOD2 = 911382323;
const ll p1 = 71, p2 = 97;
const ll maxN = 1e18;


void solve(){
    int n; cin>>n;
    unordered_map<int, int> m; 
    int mx = 0;
    for(int i = 0; i < n; i++){
        int a; cin>>a;
        m[a]++;
        mx = max(mx, m[a]);
    }
    cout<<n - mx<<endl;



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--){solve();}
    return 0;
}