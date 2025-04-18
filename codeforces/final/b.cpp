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
    vector<bool> ok(2 * n + 1, 0);
    vector<int> cant(2 * n + 1, 0);
    vector<int> c(2 * n + 1, 0);
    vector<pair<int, int>> vec(n);
    rep(i, n){
        int l, r; cin>>l>>r;
        if(l == r) {ok[l] = true; cant[l]++;}
        vec[i].first = l; vec[i].second = r;
    }

    for(int i = 1; i <= 2 * n; i++){
        c[i] = c[i - 1];
        if(ok[i]) c[i]++;
    }

    for(int i = 0; i < n; i++){
        if(vec[i].second != vec[i].first){
            if(c[vec[i].second] - c[vec[i].first - 1] == vec[i].second - vec[i].first + 1) cout<<0;
            else cout<<1;
        } else {
            if(cant[vec[i].first] > 1) cout<<0;
            else cout<<1;
        }
       
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