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

int sol(int num) {
    int ans = 0;
    while(num) {
        int res = num % 10;
        ans += res * res;
        num /=10;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];

    rep(i, n) {
        rep(j, 300) {
            v[i] = sol(v[i]);
        }
    }

    map<int, int> m;
    rep(i, n) m[v[i]]++;

    int ans = 0;
    for(auto [a, b] : m) {
        if(b > 1) {
            ans += (b * (b - 1)) / 2;
        }
    }
    cout << ans << endl;
    return;
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}