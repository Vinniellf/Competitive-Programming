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

const ll MOD = 998244353LL;
const int INF = 1e9;
vector<int> m;
int ans = 0;
int k, len;

struct CentroidDecomposition {
	vector<vector<int>> tree; // it's not vector<vector<int>>!
	vector<bool> removed;
	vector<int> sub;
	vector<int> cnt;

	CentroidDecomposition(vector<vector<int>> &tree) : tree(tree) {
		int n = tree.size();
		sub.resize(n);
		removed.resize(n, false);
		cnt.resize(n + 1, 0);
		build(0, -1);
	}

	void build(int u, int p) {
		int n = dfs(u, p);
		int centroid = dfs(u, p, n);
		
		cnt[0] = 1;
		vector<int> distances;
		
		for (auto v : tree[centroid]) {
			if (removed[v]) continue; // Ignoramos los subárboles muertos
			
			// 1. Primero calculamos y contamos usando lo ya visto
			vector<int> subt_dist;
			get_dist(v, centroid, 1, subt_dist); 	
			
			// 2. DESPUÉS añadimos las distancias de este subárbol y acumulamos en distances para borrarlo posteriormente
			for (int d : subt_dist) {
				cnt[d]++;               
				distances.pb(d);
			}
		}
		
		// Limpiamos el arreglo cnt para el siguiente centroide en O(tamaño del componente)
		for (int d : distances) {
			cnt[d] = 0;
		}
		cnt[0] = 0; 
		
		// Removemos el centroide y seguimos con la construcción
		removed[centroid] = true;
		for (auto v : tree[centroid]) {
			if(!removed[v]) build(v, centroid);
		}
	}

	void get_dist(int u, int p, int d, vector<int> &distances) {
		distances.pb(d);
		if(k - d >= 0) ans += cnt[k - d];
		for (auto v : tree[u]) if (v != p && !removed[v]) get_dist(v, u, d + 1, distances);
	}

	int dfs(int u, int p) {
		sub[u] = 1;

		for (auto v : tree[u])
			if (v != p && !removed[v]) sub[u] += dfs(v, u);

		return sub[u];
	}

	int dfs(int u, int p, int n) {
		for (auto v : tree[u])
			if (v != p and sub[v] > n/2 and !removed[v]) return dfs(v, u, n);

		return u;
	}

};

void solve() {
    int n; cin >> n >> k;
    vector<vector<int>> g(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
		u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    CentroidDecomposition cd(g);
	cout << ans << endl;
}

signed main(){
    #ifndef ONLINE_JUDGE 
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif
    fastio;
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}