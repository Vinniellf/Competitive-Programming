#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define cases ll T=0;cin>>T;while(T--)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define REP(i,k,n) for (int i = k; i <n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define PI 3.14159265359

typedef long double ld;
typedef long long ll;

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    vector<int> al(26, 0);
    for(int i = 0; i < n; i++){
        al[s[i] - 'a']++;
    }
    vector<pair<int, int>> vec;
    for(int i = 0 ; i < 26; i++){
        if(al[i] == 0) continue;
        vec.push_back({al[i], i});
    }
    sort(all(vec));
    for(int i = 0 ; i < n; i++){
        if(s[i]  - 'a' == vec[0].second){
            s[i] = vec[vec.size() - 1].second + 'a';
            break;
        }
    }
    cout<<s<<endl;
    
    
    return;
}

signed main(){
    fastio;
    cases{
        solve();
    }

    return 0;
}