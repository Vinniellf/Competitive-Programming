#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define PI 3.14159265359
#define int long long

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
const int INF = 1e9;

int sol(int n) {
    if(n == 0 || n == 1) return n;
    if(n == 2) return 3;
    int c = 0;
    for(int i = 1; i <= 60; i++) {
        int val = (1LL << i) - 1;
        if(val >= n) {
            c = i;
            break;
        }
    }
    int val1 = (1LL << c) - 1;

    if(n == val1) return c;
    return min(c + val1 - n, c + sol(n - (1LL << (c - 1)) + 2));

}

void solve() {
    int l, r; cin >> l >> r;
    int ans = 0LL;
    for(int i = l; i <= r; i++) {
        ans = (ans + sol(i)) % MOD;
    }
    cout << ans << endl;
}

signed main(){
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