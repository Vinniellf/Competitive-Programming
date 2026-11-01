#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define int long long

vector<bool> is_leaf;
vector<int> cnt;
vector<int> k;
vector<int> ans;
int q;

struct CentroidDecomposition {
	vector<vector<int>> tree; 
	vector<int> cnt;
	vector<int> sub;
	vector<int> removed;

	CentroidDecomposition(vector<vector<int>> &tree) : tree(tree) {
		int n = tree.size();
		cnt.resize(n + 1, 0);
		sub.resize(n);
		removed.resize(n, false);
		build(0, -1);
	}

	void build(int u, int p) {
		int n = dfs(u, p); 
		int centroid = dfs(u, p, n); 
		if (p == -1) p = centroid; 
		removed[centroid] = true;

		vector<int> neighbors(tree[centroid].begin(), tree[centroid].end());
        
        if(is_leaf[centroid] == 1) cnt[0] = 1;
        vector<int> distances;
		for (int v : neighbors) {
            vector<int> subtre_dist;
            if(!removed[v]) get_dist(v, centroid, 1, subtre_dist);

            for(int d: subtre_dist) {
                cnt[d]++;
                distances.push_back(d);
            }
	    }

        for(int d: distances) {
            cnt[d] = 0;
        }
        cnt[0] = 0;

        for (int v : neighbors) {
			if(!removed[v]) build(v, centroid);
	    }
	}

	int dfs(int u, int p) {
		sub[u] = 1;

		for (auto v : tree[u])
			if (v != p && !removed[v]) sub[u] += dfs(v, u);

		return sub[u];
	}

	int dfs(int u, int p, int n) {
		for (auto v : tree[u])
			if (v != p && sub[v] > n/2 && !removed[v]) return dfs(v, u, n);

		return u;
	}

	void get_dist(int u, int p, int d, vector<int> &subtre_dist) {
        if(is_leaf[u]) {
            subtre_dist.push_back(d);
            rep(j, q) if(k[j] - d >= 0) ans[j] += cnt[k[j] - d];
        }
        for(auto v: tree[u]) {
            if(v != p && !removed[v]) get_dist(v, u, d + 1, subtre_dist);   
        }
    }
};

void solve() {
    int n; cin >> n >> q;
    vector<vector<int>> g(n);
    is_leaf.resize(n, false);
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
		u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    rep(i, n) {
        if((int)g[i].size() == 1) is_leaf[i] = true;
    }

    k.resize(q);
    ans.resize(q, 0);
    rep(i, q) {
        cin >> k[i]; 
    }

    CentroidDecomposition cd(g);
    rep(i, q) cout << ans[i] << endl;
    return;
}

signed main(){
    #ifndef ONLINE_JUDGE 
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif
    fastio;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}