#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define PI 3.14159265359
#define int long long

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1000001;
bool prime[N + 1];
vector<int> pr;
const int K = 50;

void Sieve() {
  memset(prime, true, N);
  prime[0] = prime[1] = false;
  for (int p = 2; p * p <= N; p++) {
    if (prime[p]) {
      for (int64_t m = int64_t(p) * p; m <= N; m += p) {
        prime[m] = false;
      }
    }
  }
}

void solve() {
    int k; cin >> k;
    vector<pair<int, int>> v;
    int copia = k;
    for(int i = 0; i < (int)pr.size(); i++) {
        int c = 0;
        while(copia % pr[i] == 0) {
            c++;
            copia /= pr[i];
        }
        if(c == 0) continue;
        v.push_back({pr[i], c});
    }
    if(copia > 1) {
        v.push_back({copia, 1});
    }

    int len = (int)v.size();

    int ans = 1;
    rep(i, len) {
        int count = 0;
        int factor = v[i].first;
        int exp = v[i].second;
        for(int j = 1; j <= 50; j++) {
            count++;
            int a = j;
            while(a % factor == 0) {
                count++;
                a /= factor;
            }
            if(count >= exp) {ans = max(ans, factor * j); break;}
            
        }
    }

    cout << ans << endl;
    
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Sieve();
    solve();

    return 0;
}
