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
    int n; cin>>n;
    int ans = 0;
    int b = 0;
    for(int i = 0; i < n; i++){
        int a; cin>>a;
        ans += a;
        if(ok[ans]) b++;
    }
    cout<<b<<endl;
    
    
    return;
}

signed main(){
    fastio;
    for(int i = 1; i < 100; i += 2){
        ok[i * i] = 1;
    }
    cases{
        solve();
    }

    return 0;
}