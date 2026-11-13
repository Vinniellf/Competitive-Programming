#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define int long long
#define all(v) v.begin(), v.end()

const double EPS = 1e-7;

optional<pair<double, double>> inter(pair<double, double> a, pair<double, double> b) {
    if (a.first > a.second) swap(a.first, a.second);
    if (b.first > b.second) swap(b.first, b.second);

    double l = max(a.first, b.first);
    double r = min(a.second, b.second);

    if (l - r > EPS) return nullopt; 
    if (l > r) l = r; 

    return make_pair(l, r);
}

bool ok(double mid, vector<int>& v, vector<int>& x) {
    double l = 0.0;
    double r = 1e10;
    rep(i, (int)v.size()) {
        double l1 = x[i] - v[i] * mid;
        double r1 = x[i] + v[i] * mid;
        auto res = inter({l,r}, {l1, r1});
        if(res) {
            l = res->first;
            r = res->second;
        } else {
            return false;
        }
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vector<int> x(n), v(n);
    rep(i, n) cin >> x[i];
    rep(i, n) cin >> v[i];


    double l = 1e-7;
    double r = 1e18;
    
    while(r - l > EPS) {
        double mid = (r + l) / 2;
        if(ok(mid, v, x)) r = mid;
        else l = mid;
    }

    cout << fixed << setprecision(6) << r << endl;
    return;
}

signed main(){
    #ifndef ONLINE_JUDGE 
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif
    fastio;
    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}