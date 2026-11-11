#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define REP(i,k,n) for (int i = k; i <n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define PI 3.14159265359
#define F first
#define S second
#define int long long

typedef long double ld;
const int MAX = 2e5 + 5;
vector<int> Y, H;

bool ok(int t, int cant, int H1) {
    auto it = upper_bound(Y.begin(), Y.end(), t);

    // Corregido: antes era v.begin(), pero debe ser Y.begin() porque it es de Y
    if (it == Y.begin()) {
        return false;
    } else {
        int idx = distance(Y.begin(), it) - 1;
        
        sqrt_dec::update(0, idx, -H1);
        int target = sqrt_dec::query(0, idx); // Retorna cantidad de nodos >= 0
        sqrt_dec::update(0, idx, H1); // Revertir el estado
        
        return target >= cant;
    }
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    H.resize(n, 0);
    Y.resize(n, 0);

    // Corregido: in debe ser un vector de pares
    vector<pair<int, int>> in(n);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        in[i] = {a, b};
    }
    sort(all(in));

    rep(i, n) {
        Y[i] = in[i].first;   // Corregido: in[i].first
        H[i] = in[i].second;  // Corregido: in[i].second
        v[i] = H[i] - Y[i];
    }

    sqrt_dec::build(n, v);

    int q; cin >> q;
    rep(i, q) {
        int cant, h1; cin >> cant >> h1;
        int l = -1LL; // Sugerencia: iniciar l en -1 para rangos estrictos en binary search
        int r = 2e18;
        while(r - l > 1LL) {
            int mid = l + (r - l) / 2; // Evita overflow
            if(ok(mid, cant, h1)) r = mid;
            else l = mid;
        }

        cout << r << "\n"; // Usa "\n" en lugar de endl por rendimiento
    }
}

signed main() {
    fastio;
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}