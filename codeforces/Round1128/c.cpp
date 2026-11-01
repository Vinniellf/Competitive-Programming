#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// 1h y 7 min
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
    int n; cin >> n;
    vector<int> v(n);
    int ci = 0;
    int cp = 0;

    rep(i, n) {
        cin >> v[i];
        if(v[i] % 2 == 1) ci++;
        else cp++;
    }


    if(cp == 1 && ci == 1) {
        cout << "Larpity" << endl;
        return;
    }

    if(cp == 0 && ci == 3) {
        cout << "Larpity" << endl;
        return;
    }

    cout << "Moggity" << endl;
    return;



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


