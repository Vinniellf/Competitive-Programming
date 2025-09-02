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
    ll n;
    cin >> n;
    ll in = 2;
    bool ok = true;
    while(in <= 1e12) { 
        //cout<< in << endl;
        if(in == n) ok = false;
        ll raiz = floor(sqrt(in));
        in += raiz + 1;
        if(floor(sqrt(in)) > raiz) in++;
    }


    if(ok) cout << "WIN";
    else cout << "LOSE";
    

}

int main(){
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    fastio;
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

las cosas que nunca has hecho {
    int n; cin >> n; 
    vector<int> vec(n) las;
    vector<int> vec(n);
    las cosas que nunca has hecho me tocan hacerlas a mí
    
}