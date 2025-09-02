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
const int MAXN = 1e3 + 2;
const int MAXK = 21;

int mat[1001][21];
ll exp1[21];

void solve() {
    int n, k; cin >> n >> k;
    unordered_map<ll, int> m;

    exp1[0] = 1;
    for(int i = 1; i < 21; i++){
        exp1[i] = exp1[i - 1] * 3;
    }

    for(int i = 0; i < n; i++) {
        ll ga = 0;
        for(int j = 0; j < k; j++) {
            cin >> mat[i][j];  
            ga += mat[i][j] * exp1[j];
        }
        m[ga] = i + 1;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll count = 0;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            ll val = 0;
            for(int l = 0; l < k; l++) {
                if(mat[i][l] == mat[j][l]){
                    val += mat[i][l] * exp1[l];
                } else {
                    val += (3 - mat[i][l] - mat[j][l]) * exp1[l];
                }
            }
            if(m[val] != 0) count++;
        }
        count = count / 2;
        ans += count * (count - 1) / 2;
    }

    cout << ans;


    

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