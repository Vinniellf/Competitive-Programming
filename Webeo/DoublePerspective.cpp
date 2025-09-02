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

struct tupla{
    int first, second, third;
};

void solve() {
    int n; cin >> n;
    vector<tupla> v(n);
    map<int, int> m;
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        v[i].third = i + 1;
        m[v[i].first] = -1;
    }
    
    sort(all(v), [](const tupla &a, const tupla &b) {
        if (a.first != b.first) return a.first < b.first;
        if (a.second != b.second) return a.second < b.second;
        return a.third < b.third;
    });

    vector<tupla> ans;
    for(int i = 0; i < n; i++) { 
        m[v[i].first] = v[i].third;
    }

    for(auto ga : m) {
        ga
    }



    




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