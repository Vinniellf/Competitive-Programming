#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define PI 3.14159265359
#define int long long

const int N = 1000005;
bool ok[N + 1];

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    unordered_map<int, int> m;

    memset(ok, true, N);
    rep(i, n) {
        cin >> v[i];
        m[v[i]]++;
    }

    sort(v.begin(), v.end());
    for(auto [a, b] : m) {
        if(!ok[a]) continue;
        for(int j = 2 * a; j <= N; j += a) {
            ok[j] = false;
        }
    }

    int ans = 0;
    rep(i, n) if(ok[v[i]] && m[v[i]] == 1) ans++;
    cout << ans << endl;
    
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();

    return 0;
}