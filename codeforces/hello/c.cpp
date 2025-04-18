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
    int l, r; cin>>l>>r;
    int bi = 31 - __builtin_clz(r);
    int a;
    int ans = 0;

    for(int i = bi; i >= 0; i--){
        if(((1 << i) & r) == ((1 << i) & l)) {ans += ((1 << i) & r); bi--;}
        else break;
    }

    r -= ans; l -= ans;
    if((1 << bi) == r) a = ans + r - 1;
    else a = ans + (1 << bi);

    cout<<a - 1<<" "<<a<<" "<<a + 1<<endl;
    
    return;
}

signed main(){
    fastio;
    cases{
        solve();
    }

    return 0;
}