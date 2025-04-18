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
    vector<int> vec(n);
    rep(i, n) cin>>vec[i];
    bool ok = false;
    for(int i = 0; i < n - 1; i++){
        if(max(vec[i],  vec[i + 1]) < 2 * min(vec[i], vec[i + 1])) ok = true;
    }
    cout<<(ok ? "YES" : "NO");
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