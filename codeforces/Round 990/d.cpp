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
const int maxN = 1e4;
const int INF = 1e9 + 5;

void solve(){
    int n; cin>>n;
    vector<int> vec(n);
    vector<int> ga;
    multiset<int> ans, m;
    ans.insert(INF);
    rep(i, n) {
        cin>>vec[i];
        m.insert(vec[i]);
    }

    for(int i = 0; i < n; i++){
        if(*ans.begin() >= *m.begin()){
            if(vec[i] == *m.begin()){
                ga.push_back(vec[i]);
            } else {
                ans.insert(vec[i] + 1);
            }
        } else{
            ans.insert(vec[i] + 1);
        }
        m.erase(m.find(vec[i]));
    }

    for(auto p : ans){
        ga.push_back(p);
    }

    for(int i = 0; i < ga.size() - 1; i++){
        cout<<ga[i]<<" ";
    }

    cout<<endl;
    
    
    
    return;
}

signed main(){
    fastio;
    cases{
        solve();
    }

    return 0;
}