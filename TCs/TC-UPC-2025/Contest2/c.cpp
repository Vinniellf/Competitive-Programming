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
    string s; cin >> s;
    vector<int> vec;
    int count = 0;
    int mn = INF;
    int a = 0;
    int b1 = 0,  b2 = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'B') {
            if(count != 0) {vec.push_back(count); mn = min(mn, count); a += count; b1++;}
            b2++;
            vec.push_back(-1);
            count = 0;
        } else count++;
    }
    if(count > 0) {vec.push_back(count); mn = min(mn, count); a += count; b1++;}
    /*rep(i, vec.size()) cout << vec[i] << " ";
    cout << endl;

    cout << b1 << " " << b2 << " " << a << " " << mn << endl;*/

    if(b1 == 0 || b2 == 0) {cout << 0 << endl; return;}
    if(b1 <= b2) {cout<< a << endl; return;}
    else cout << a - mn << endl;
    

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