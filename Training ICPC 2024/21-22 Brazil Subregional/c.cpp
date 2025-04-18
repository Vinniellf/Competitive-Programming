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
    int b, n; cin>>b>>n;
    b++;
    vector<int> vec(n);
    rep(i, n) cin>>vec[i];
    int res = 0;
    for(int i = n - 1; i >= 0; i--){
        if((n - 1 - i) % 2 == 0) res += vec[i];
        else res -= vec[i];
        res %= b;
    }
    res = (res + b) % b;


    if(res == 0) {cout<<0<<" "<<0; return;}

    int k1 = b - res, k2 = res;
    for(int i = 0; i < n; i++){
        if((n - 1 - i) % 2 == 0) {
            if(vec[i] >= k2) {cout<<i + 1<<" "<<vec[i] - k2; return;}
        }
        else {
            if(vec[i] >= k1) {cout<<i + 1<<" "<<vec[i] - k1; return;}
        }
    }
    cout<<-1<<" "<<-1;

    return;
}

signed main(){
    fastio;
    solve();

    return 0;
}