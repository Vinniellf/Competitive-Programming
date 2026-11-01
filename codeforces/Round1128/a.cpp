#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//13 - 1 WA

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
    int n; cin >> n;
    string s; cin >> s;
    int c1 = 0;
    int c0 = 0;
    int l = 0, r = 0;
    bool ok = 0;
    rep(i, n) {
        if(s[i] == '1') c1++;
        else c0++;
        if(c1 == 1 && !ok) {l = i; ok = 1;}
        if(s[i] == '1') r = i;
    }

    if(c1 == 1) {
        cout << 0 << endl;
    } else if(c1 == 2) {
        cout << 1 << endl;
    } else {
        cout << r - l<< endl;
    }
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