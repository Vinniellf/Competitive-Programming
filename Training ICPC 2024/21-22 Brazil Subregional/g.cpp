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
    ll num; cin>>num;
    vector<ll> vec(100, 0LL);
    vec[0] = 1;
    vec[1] = 2;
    for(int i = 2; i <= 80; i++){
        vec[i] = vec[i - 1] + vec[i - 2];
    }
    if(num == 1) {cout<<"B";return;}
    
    cout<<vec[80];
    string ans;
    for(int i = 80; i >= 1; i--){
        while(num % vec[i] == 0){
            num /= vec[i];
            for(int l = 0; l < i; l++){
                ans += 'A';
            }
            ans += 'B';
        }
    }
    
    if(num != 1) cout<<"IMPOSSIBLE";
    else cout<<ans;
    
    return;
}

signed main(){
    fastio;
    solve();

    return 0;
}