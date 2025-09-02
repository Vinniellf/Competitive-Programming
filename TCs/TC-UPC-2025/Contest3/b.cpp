#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define PI 3.14159265359

typedef long double ld;
typedef long long ll;

const ll MOD = 998244353LL;
const int INF = 1e9;
const int MAXN = 1e6 + 5;


void solve() {
    int n; cin >> n;
    vector<int> vec(n), ans0(n + 1), ans1(n + 1);
    rep(i, n) cin >> vec[i];
    int q; cin >> q;
    int x = 0;
    int x1 = 0;
    for(int j = 0; j < n; j++){
        if(vec[j] == x1) x++;
        x1 = (x1 + 1) % 2;
        ans0[j + 1] = x;
        ans1[j + 1] = j + 1 - x; 
    }
    rep(i, q) {
        int a, b; cin >> a >> b;
        cout << min(ans0[b] - ans0[a - 1], ans1[b] - ans1[a - 1]) << endl;
    }
    

}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}