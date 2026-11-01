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

void solve() {
    int n, k; cin >> n >> k;

    vector<int> v(n), p(n + 1, 0);
    ordered_multiset mset;

    rep(i, n) {
        cin >> v[i];
        p[i + 1] = p[i] + v[i];
    }

    rep(i, n) {
        mset.insert({v[i], i});
        if(i >= k - 1) {
            int a = mset.find_by_order((k - 1) / 2)->first;
            int x = (k - 1) / 2;
            int y = k - x;
            int mx = (p[i + 1] - p[i + 1 - x] - x * a) - (p[i + 1 - x] - p[i + 1 - x - y] - y * a);
            if(k % 2 == 0) {
                int b = mset.find_by_order(k / 2)->first;
                x = k / 2;
                y = k - x;
                mx = max(mx, p[i + 1] - p[i + 1 - x] - x * b) - (p[i + 1 - x] - p[i + 1 - x - y] - y * b);
            } 
            cout << mx << " ";
            mset.erase({v[i - k + 1], i - k + 1});
        }
    }
    cout << endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}