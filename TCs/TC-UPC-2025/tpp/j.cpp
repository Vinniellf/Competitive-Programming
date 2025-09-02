#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n), c(n + 1), p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    
    vector<pair<pair<int, int>, pair<int, int>>> ans;
    int mx = c[1];
    ans.push_back({{p[0] , c[1]}, {1, 0}});
    for(int i = 1; i < n; i++) {
        vector<pair<pair<int, int>, pair<int, int>>> current;
        current.push_back({{p[i], mx + c[1]}, {1, 0}});
        mx = max(mx, mx + c[1]);
        bool ok = false;
        int curr_mx = mx;
        int peso, valor, counter_curr, counter_war;
        for(int j = 0; j < ans.size(); j++) {
            peso = ans[j].first.first;
            valor = ans[j].first.second;
            counter_curr = ans[j].second.first;
            counter_war = ans[j].second.second;
            if(peso <= p[i]) counter_war++;
            if(peso == p[i]) {
                ok = true;
            }
            counter_curr++;
            valor = valor - c[counter_curr - 1] + c[counter_curr];
            if(peso < p[i]) valor += (p[i] - peso) * b[i];
            if(peso > p[i]) valor -= (peso - p[i]) * a[i];
            if(counter_war <= k) {
                current.push_back({{peso, valor},{counter_curr, counter_war}});
                mx = max(mx, valor);
            }
        }
        if(ok) {
            current.push_back({{p[i], curr_mx - c[counter_curr - 1] + c[counter_curr]}, {counter_curr, 0}});
            mx = max(mx, curr_mx + c[1]);
        }
        ans = current;

    }

    cout << mx;
}

signed main() {
    int t = 1;
    //cin >> t;
    while(t--) solve();
}