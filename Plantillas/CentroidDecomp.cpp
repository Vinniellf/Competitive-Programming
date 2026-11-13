struct CentroidDecomposition {
	vector<vector<int>> tree; 
	vector<int> dad;
	vector<int> sub;
	vector<int> removed;

	CentroidDecomposition(vector<vector<int>> &tree) : tree(tree) {
		int n = tree.size();
		dad.resize(n);
		sub.resize(n);
		removed.resize(n, false);
		build(0, -1);
	}

	void build(int u, int p) {
		int n = dfs(u, p); // find the size of each subtree
		int centroid = dfs(u, p, n); // find the centroid
		if (p == -1) p = centroid; // dad of root is the root itself
		dad[centroid] = p;
		
		for (auto v : tree[centroid]) {
			if(removed[v]) continue; 
			build(v, centroid);
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

	int operator[](int i) {
		return dad[i];
	}
};