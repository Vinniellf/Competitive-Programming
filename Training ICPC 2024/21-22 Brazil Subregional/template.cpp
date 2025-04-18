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
bool ok[maxN];

void solve(){
    int n, k; cin>>n>>k;
    vector<int> vec(n + 1);
    map<int, int> m;
    REP(i, 1, n + 1) {
        int a;
        cin>>vec[i]>>a;
        m[vec[i]] = a;
    }

    for(int i = 1; i <= n; i++){
        if(i == vec[i]) continue;
        if(m[i] == m[vec[i]]) continue;
        cout<<"N";
        return ;
    }
    cout<<"Y";
    
    return;
}

signed main(){
    fastio;
    solve();

    return 0;
}