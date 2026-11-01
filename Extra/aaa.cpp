#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define PI 3.14159265359
#define int long long

const int MOD = 998244353LL;
const int INF = 1e12;

void solve() {
    string base; cin >> base;
    int n = (int) base.size();    
    map<string, int> m;
    m[base]++;

    vector<int> p(n);
    rep(i, n) p[i] = i;

    int ans = 1;
    do {
        string s;
        for(int val: p) {
            s += base[val];
        }
        if(m[s] == 0) {
            ans++;
            m[s]++;
        } 

    } while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;
    for(auto [a, b]: m) {
        cout << a << endl;
    }
    return;
}

signed main(){
    #ifndef ONLINE_JUDGE 
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif
    fastio;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}