#include<bits/stdc++.h>
using namespace std;
#define int long long



void solve() {
    int n; cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];
    int l = 0, r = n - 1;
    string s;
    bool mayor = true;
    while(l < r) {
        if(mayor) {
            if(vec[l] < vec[r]) {s += 'R'; s += 'L';}
            else {s += 'L'; s += 'R';}
            mayor = false;
        } else {
            if(vec[l] < vec[r]) {s += 'L'; s += 'R';}
            else {s += 'R'; s += 'L';}
            mayor = true;
        }
        l++; r--;
    }
    if(n % 2 == 1) s += 'R';
    cout << s << endl;

    
}



signed main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}