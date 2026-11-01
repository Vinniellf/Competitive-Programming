#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define int long long

int ans = 0LL;
int l, r;

struct Bit {
    int n; 
    vector<int> bit;
    
    // Inicialización limpia
    Bit(int _n = 0) : n(_n), bit(_n + 1, 0LL) {}

    void update(int i, int x) {
        for(i++; i <= n; i += i & -i) bit[i] += x;
    }

    // CORRECCIÓN: Ahora retorna int
    int pref(int i) {
        int ret = 0;
        for(; i; i -= i & -i) ret += bit[i];
        return ret;
    }

    // CORRECCIÓN: Ahora retorna int y valida los rangos
    int query(int left, int right) {
        if (left > right) return 0;
        return pref(right + 1) - pref(left);
    }
};

struct CentroidDecomposition {
    vector<vector<int>>& tree; // CORRECCIÓN: Ahora es una referencia para no copiar el grafo
    vector<bool> removed;
    vector<int> sub;
    Bit bit_cnt;

    // Vectores reutilizables para evitar overhead de asignación de memoria
    vector<int> distances;
    vector<int> subtree_dist;

    CentroidDecomposition(vector<vector<int>> &t) : tree(t) {
        int n = tree.size();
        sub.resize(n);
        removed.resize(n, false);
        bit_cnt = Bit(n + 1);
        
        // Reservamos capacidad para que el push_back sea O(1) real
        distances.reserve(n);
        subtree_dist.reserve(n);
        
        build(0, -1);
    }

    void build(int u, int p) {
        int n = dfs(u, p); 
        int centroid = dfs_centroid(u, p, n); 
        if (p == -1) p = centroid; 

        bit_cnt.update(0, 1);
        distances.clear(); // Reutilizamos el vector en vez de crear uno nuevo

        for(int v: tree[centroid]) {
            if(!removed[v]) {
                subtree_dist.clear();
                get_dist(v, centroid, 1);

                // 1. Contamos
                for(int d: subtree_dist) {
                    int l1 = max(0LL, l - d);
                    int r1 = r - d;
                    if(l1 <= r1) {
                        ans += bit_cnt.query(l1, r1);
                    }
                }

                // 2. Agregamos al BIT
                for(int d: subtree_dist) {
                    bit_cnt.update(d, 1);
                    distances.push_back(d);
                }
            }
        }

        // Limpieza manual O(S)
        for(int d: distances) {
            bit_cnt.update(d, -1);
        }
        bit_cnt.update(0, -1);

        removed[centroid] = true;
        for (auto v : tree[centroid]) {
            if(!removed[v]) build(v, centroid);
        }
    }

    void get_dist(int u, int p, int d) {
        if (d > r) return; // CORRECCIÓN: Poda vital para evitar TLE en árboles largos
        
        subtree_dist.push_back(d);
        for(int v: tree[u]) {
            if(v != p && !removed[v]) get_dist(v, u, d + 1);
        }
    }

    int dfs(int u, int p) {
        sub[u] = 1;
        for (auto v : tree[u])
            if (v != p && !removed[v]) sub[u] += dfs(v, u);
        return sub[u];
    }

    int dfs_centroid(int u, int p, int n) {
        for (auto v : tree[u])
            if (v != p and sub[v] > n/2 and !removed[v]) return dfs_centroid(v, u, n);
        return u;
    }
};

void solve() {
    int n; 
    if (!(cin >> n >> l >> r)) return;
    
    vector<vector<int>> g(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    CentroidDecomposition cd(g);
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}