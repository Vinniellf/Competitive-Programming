#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    sort(v.begin(), v.end());

    int m; cin >> m;
    rep(i, m) {
        int target; cin >> target;
        auto it = upper_bound(v.begin(), v.end(), target);
        cout << distance(v.begin(), it) << endl;
    }
}

int main(){
    #ifndef ONLINE_JUDGE 
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif
    fastio;
    solve();

    return 0;
}