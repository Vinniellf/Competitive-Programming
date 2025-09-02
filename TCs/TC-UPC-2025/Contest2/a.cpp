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
    int k, n; cin >> k >> n;
    vector<int> vec(k, 0);
    int count = 0;
    for(int i = 0; i < n; i++) {
        int a;  cin >> a;
        a--;
        if(vec[a] == 0) count++;
        vec[a]++;
        if(count == k) {
            cout << "1";
            for(int j = 0; j < k; j++) {
                if(vec[j] == 1){
                    count--;
                }
                vec[j]--;
            }
        } else {
            cout << "0";
        }

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