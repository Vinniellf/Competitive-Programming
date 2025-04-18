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
    vector<pair<int, int>> vec(n);
    rep(i, n) cin>>vec[i].first>>vec[i].second;
    sort(all(vec));
    int cant = 0;
    int lim_queue = 0;
    int lim = vec[0].first + 10, bot = vec[0].second;
    for(int i = 1; i < n; i++){
        if(vec[i].second != bot){
            lim_queue = vec[i].first;
            cant++;
        } else {
            if(vec[i].first < lim){
                lim = vec[i].first + 10;
            } else {
                if(cant == 0){
                    lim = vec[i].first + 10;
                } else {
                    lim = max(lim, lim_queue) + 10;
                    bot = (bot + 1) % 2;
                    i--;
                }
                cant = 0;
            }

        }
    }
    if(cant > 0) lim = max(lim, lim_queue) + 10;
    cout<<lim;

    
    return;
}

signed main(){
    fastio;
    solve();

    return 0;
}