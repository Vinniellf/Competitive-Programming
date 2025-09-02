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
    vector<int> ans(n, 0), factor;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {factor.push_back(i); factor.push_back(n / i);}
    }

    rep(i, n) {
        rep(j, factor.size()) {
            //cout << factor[j] << "ga\n";
            if(i + factor[j] < n && ans[i] == ans[i + factor[j]]) {
                ans[i + factor[j]]++;
            }
        }
    }

    string s;
    rep(i, n) {
        char letter = ans[i] + 'a';
        s += letter;
    }
    cout << s << endl;
    

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