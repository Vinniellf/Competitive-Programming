#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// 34 - 1 WA
using namespace __gnu_pbds;
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define PI 3.14159265359

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

typedef tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_multiset;

const ll MOD = 998244353LL;
const int INF = 1e9 + 5;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    int mx = 0;
    int mn = INF;
    rep(i, n) {
        cin >> v[i];
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);
    }
    if(mx == 0) {
        cout << 0 << endl; 
        return;
    }
    if(mx == mn) {
        cout << mx << endl;
        return;
    }
    int ans = mx;
    bool ok = 0;
    for(int i = 30; i >= 0; i--) { 
        if(ok) {
            mx |= (1 << i);
            continue;
        }
        if(((1 << i) & mx) == ((1 << i) & mn)) {
            continue;
        } else {
            ok = 1;
            mx |= (1 << i);
        }
    }

    cout << mx << endl;
    return;

}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}



// 1 0 1 0 0 0 0
// 0 1 0 0 0 0 0