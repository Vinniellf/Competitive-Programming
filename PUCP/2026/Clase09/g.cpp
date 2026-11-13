#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define all(v) v.begin(), v.end()

int n; 

bool ok(int num, vector<int> &a, vector<int> &b) {
    int c = 0;
    rep(i, n) {
        if(b[i] >= c && (num - 1 - c) <= a[i]) c++; 
    }

    if(c >= num) return true;
    else return false;
}

void solve() {
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
    }

    int l = 0, r = n + 1;
    while(r - l > 1) {
        int mid = (r + l) / 2;
        if(ok(mid, a, b)) l = mid;
        else r = mid;
    }

    cout << l << endl;
    
}

int main(){
    #ifndef ONLINE_JUDGE 
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif
    fastio;
    int t; cin >> t;
    while(t--) solve();

    return 0;
}