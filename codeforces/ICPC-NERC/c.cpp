#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1000003;
//const ll MOD2 = 911382323;
const ll p1 = 71, p2 = 97;
const ll maxN = 1e18;


void solve(){
    int n, a; cin>>n;
    map<int, int> m; 
    for(int i = 0; i < n; i++){
        cin>>a;
        m[a]++;
    }

    vector<int> ans;
    for(auto it = m.begin(); it != m.end(); it++){
        while(it->second >= 2) {ans.push_back(it->first); it->second -= 2;}
    }

    if(ans.size() < 4) {cout<<"NO\n"; return;}
    cout<<"YES\n";
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[ans.size() - 2]<<" "<<ans[1]<<" "<<ans[0]<<" "<<ans[ans.size() - 1]<<" "<<ans[ans.size() - 2]<<" "<<ans[ans.size() - 1]<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t ; cin>>t;
    while(t--){solve();}
    return 0;
}