#include <bits/stdc++.h>

using namespace std;


void solve() {
    long long n, k; cin >> n >> k;
    vector<long long> a(n), b(n), c(n + 1), p(n);
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
    vector<pair<pair<long long, long long>, pair<long long, long long>>> ans;
    long long mx = c[1];
    ans.push_back({{p[0] , c[1]}, {1, 0}});
    for(int i = 1; i < n; i++) {
        vector<pair<pair<long long, long long>, pair<long long, long long>>> current;
        current.push_back({{p[i], mx + c[1]}, {1, 0}});
        mx = max(mx, mx + c[1]);
        for(int j = 0; j < ans.size(); j++) {
            long long peso = ans[j].first.first;
            long long valor = ans[j].first.second;
            long long counter_curr = ans[j].second.first;
            long long counter_war = ans[j].second.second;
            if(peso <= p[i]) counter_war++;
            counter_curr++;
            valor = valor - c[counter_curr - 1] + c[counter_curr];
            if(peso < p[i]) valor += (p[i] - peso) * b[i];
            if(peso > p[i]) valor -= (peso - p[i]) * a[i];
            if(counter_war <= k) {
                current.push_back({{peso, valor},{counter_curr, counter_war}});
                mx = max(mx, valor);
            }
        }
        ans.clear();
        ans = current;

    }

    cout << mx;
}

int main() {
    int t = 1;
    //cin >> t;
    while(t--) solve();
}