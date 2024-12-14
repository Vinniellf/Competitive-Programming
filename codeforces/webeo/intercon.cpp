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
const ll MOD = 1e9 + 7;

void solve(){    
    int n; cin>>n;
    set<ll> sn;
    map<ll, ll> mn;
    vector<ll> vec(n);
    vector<ll> a(n, 0LL), b(n, 0LL);

    for(int i = 0; i < n; i++) cin>>vec[i];

    for(int i = 0; i < n - 1; i++){
        a[i] += (i == 0 ? 0 : a[i - 1]) + vec[i];
        sn.insert(vec[i]);
        mn[vec[i]]++;
        auto it = sn.find(vec[i]);
        int count = 0;
        for(auto j = ++it; j != sn.end(); j++){
            count++;
            ll num = *j;
            a[i] -= (mn[num] * num);
            a[i] += (mn[num] * vec[i]);
            mn[vec[i]] += mn[num];
        }
        rep(l, count){
            auto k = sn.end();
            sn.erase(--k);
        }
        //a[i] %= MOD;
    }
    sn.clear();
    mn.clear();   

    sn.insert(0LL);
    for(int i = n - 1; i > 0; i--){
        b[i] += (i == n - 1 ? 0LL : b[i + 1]) + vec[i];
        sn.insert(vec[i]);
        mn[vec[i]]++;
        auto it = sn.find(vec[i]);
        int count = 0;
        for(auto j = --it; j != sn.begin(); j--){
            count++;
            ll num = *j;
            b[i] -= (mn[num] * num);
            b[i] += (mn[num] * vec[i]);
            mn[vec[i]] += mn[num];
        }
        rep(l, count){
            auto k = sn.begin();
            sn.erase(++k);
        }
        //b[i] %= MOD;
    }

    ll ans = 0LL;
    for(int i = n - 2; i >= 0; i--){
        b[i] = (b[i] + b[i + 1]) % MOD;
    }


    for(int i = 0; i < n - 1; i++){
        ans = (ans + (a[i] % MOD) * b[i + 1]) % MOD;
    }
    cout<<ans<<endl;
    sn.clear();
    mn.clear();   
    a.clear();
    b.clear();
    return;
}

signed main(){
    fastio;
    cases{
        solve();
    }

    return 0;
}