#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < n; ++i)
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1e9 + 7;
const ll p1 = 43;
const ll p2 = 29;

void solve() {
    string s; cin >> s;
    int len = (int)s.size();
    int ans = len;

    vector<ll> h1(len + 1, 0), pw1(len + 1, 1);
    vector<ll> h2(len + 1, 0), pw2(len + 1, 1);

    rep(i, len) {
        h1[i + 1] = (h1[i] * p1 + s[i] - 'a' + 1) % MOD;
        pw1[i + 1] = pw1[i] * p1 % MOD;

        h2[i + 1] = (h2[i] * p2 + s[i] - 'a' + 1) % MOD;
        pw2[i + 1] = pw2[i] * p2 % MOD;
    }

    unordered_map<ll, pair<int, int>> m1;
    m1.reserve(2 * len);

    for(int L = 2; L <= len / 2; L++) {
        m1.clear();

        for(int i = 1; i + L - 1 <= len; i++) {
            int j = i + L - 1;

            ll a = (h1[j] - h1[i - 1] * pw1[L] % MOD + MOD) % MOD;
            ll b = (h2[j] - h2[i - 1] * pw2[L] % MOD + MOD) % MOD;
            ull key = ((ull)a << 32) | (ull)b;
            auto &v = m1[key];

            if(i > v.first) {
                v.first = j;
                v.second++;

                ans = min(ans, len + L - v.second * (L - 1));
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}