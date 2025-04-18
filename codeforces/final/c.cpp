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
    ll n, k; cin>>n>>k;
    if(k == 1){
        cout<<(n * n + n)/2<<endl;
    } else {
        vector<ll> vec; 
        vector<bool> ok;
        while(n >= k){
            vec.push_back((n + 1)/2);
            if(n % 2 == 1){
                ok.push_back(true);
                
            } else{
                ok.push_back(false);

            }
            n /= 2;
        }   
        ll ans = 0LL;
        for(int i = vec.size() - 1; i >= 0; i--){
            if(!ok[i]) continue;
            ll sum = vec[i];
            ll c = 1LL;
            for(int j = i - 1; j >= 0; j--){
                sum = sum * 2 + vec[j] * c;
                c *= 2LL;
            }  
            ans += sum;
        }
        cout<<ans<<endl;
    }
    
    return;
}

signed main(){
    fastio;
    cases{
        solve();
    }

    return 0;
}