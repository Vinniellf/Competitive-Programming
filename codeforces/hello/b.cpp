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
    int n, k; cin>>n>>k;

    map<int, int> m;
    rep(i, n) {
        int a; cin>>a;
        m[a]++;
    }
    vector<int> vec;
    
    int ans = m.size();

    for(auto p : m){
        vec.push_back(p.second);
    }

    sort(all(vec));

    for(int i = 0; i < vec.size() - 1; i++){
        if(k - vec[i] < 0) break;
        ans--;
        k -= vec[i];
    }

    cout<<ans<<endl;

    return;
}

signed main(){
    fastio;
    cases{
        solve();
    }

    return 0;
}