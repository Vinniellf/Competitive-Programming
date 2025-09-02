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

vector<int> primes;

void sieve(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            primes.pb(i);
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    map<int, int> freq;
    vector<int> factors;
    for (int i = 0; i < primes.size(); i++) {
        if (k % primes[i] == 0) {
            int ft = 1;
            while (k % primes[i] == 0) {
                ft *= primes[i];
                k /= primes[i];
            }
            factors.pb(ft);
            freq[ft]++;
        }
    }
    if (k > 1) {
        freq[k]++;
        factors.pb(k);
    }

    map<int, int> freq_ans;
    for (int i = 0; i < n; i++) {
        for (int f : factors) {
            if (a[i] % f == 0) {
                int count = 0;
                while (a[i] % f == 0) {
                    count++;
                    a[i] /= f;
                }
                freq_ans[f] += count;
            }
        }
    }

    for (auto& p : freq) {
        if (freq_ans[p.first] < p.second) {
            cout << "No" << endl;
            return;
        } 
    }
    cout << "Yes" << endl;


}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;
    sieve(MAXN);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}