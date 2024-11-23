#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1000003;
//const ll MOD2 = 911382323;
const ll p1 = 71, p2 = 97;
const ll maxN = 1e18;


void solve(){
    int n; cin>>n; 
    vector<int> vec(n);
    for(int i = 0; i < n; i++) {
        cin>>vec[i];}

    bool ok = true;
    for(int i = 0; i < n - 1; i++) {
        if(vec[i] == i + 1) continue;
        if((vec[i] == i + 2) && (vec[i + 1] == i + 1)) {i++; continue;}
        ok = false; 
        break;
    }
    cout<<(ok ? "YES": "NO");
    cout<<endl;
    return;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--){solve();}
    return 0;
}