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
    string s; cin >> s;
    long long len = s.size();
    long long res = 0LL;
    for(long long i = 0; i < min(len, 10LL); i++) {
        res *= 10LL;
        res += (s[i] - '0');
    }

    long long zeros = len - min(len, 10LL);

    vector<pair<long long, long long>> ans;
    for(long long i = 2; i <= 1e6 + 5; i++) {
        // if(i > res) break;  
        long long c = 0;
        while(res % i == 0) {
            c++;
            res /= i;
        }
        if(i == 2 || i == 5) c += zeros;
        if(c == 0LL) continue;
        ans.push_back({i, c});
    }

    if(res > 1LL) ans.push_back({res, 1LL});


    cout << ans.size() << endl;
    for(pair<long long, long long> u : ans) {
        cout << u.first << " " << u.second << endl;
    }
    return;
}

int main(){
    // freopen("in.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}