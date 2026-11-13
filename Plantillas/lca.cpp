struct LCA {
    int LOG;
    vector<int> d;
    vector<vector<int>> up;

    LCA(const vector<vector<int>>& g, int r = 0)
        : LOG(__lg(g.size()) + 1), d(g.size()),
          up(LOG, vector<int>(g.size(), r)) {
        vector<int> q{r};
        for (int i = 0; i < (int)q.size(); ++i) {
            int v = q[i];
            for (int u : g[v]) if (u != up[0][v]) {
                d[u] = d[v] + 1;
                up[0][u] = v;
                for (int j = 1; j < LOG; ++j)
                    up[j][u] = up[j-1][up[j-1][u]];
                q.push_back(u);
            }
        }
    }

    int lca(int u, int v) {
        if (d[u] < d[v]) swap(u, v);
        for (int j = LOG - 1; j >= 0; --j)
            if ((d[u] - d[v]) >> j & 1) u = up[j][u];
        if (u == v) return u;
        for (int j = LOG - 1; j >= 0; --j)
            if (up[j][u] != up[j][v])
                u = up[j][u], v = up[j][v];
        return up[0][u];
    }

    int dist(int u, int v) {
        return d[u] + d[v] - 2 * d[lca(u, v)];
    }
};