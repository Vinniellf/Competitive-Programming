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

void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    int ans = 0;
    rep(i, n) {
        cin >> v[i];
        ans += v[i];
    }

    vector<int> v1;
    if(n > 2 * (k - 1)) {
        for(int i = 0; i < k - 1; i++) {
            v1.push_back(v[i]);
            ans -= v[i];
        }

        for(int i = n - k + 1; i < n; i++) {
            v1.push_back(v[i]);
            ans -= v[i];
        }
    } else {
        v1 = v;
        ans = 0;
    }
    int len = v1.size();
    //rep(i, len) cout << v1[i] << " ";
    //cout << endl;
    for(int i = k - 1; i < len; i++) {
        ans += max(v1[i], v1[len - i - 1]);
    }
    cout << ans << endl;
    return;


}

signed main(){
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