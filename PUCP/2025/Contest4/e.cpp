#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main() {
    freopen("input.txt", "r", stdin);
    int n;
    while(cin >> n) { 
        if(n == 0) break;
        vector<int> vec(n);
        for(int i = 0; i < n; i++) {
            cin>> vec[i];
        }
        string s, ans;
        getline(cin, s, '\n'); 
        getline(cin, s, '\n');
        int cant = (s.size() + n - 1) / n;
        for(int i = s.size(); i < cant * n; i++) s += ' ';
        ans += "'";
        for(int i = 0; i < cant; i++) {
            for(int k = 0; k < n; k++) {
                ans += s[i * n + vec[k] - 1];
            }
        }
        ans += "'";

        cout << ans << endl;
    }
    return 0;
}