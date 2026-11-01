struct Bit {
    int n; 
    vector<int> bit;
    Bit(int _n = 0) : n(_n), bit(n + 1) {}
    Bit(vector<int>& v) : n(v.size()), bit(n + 1) {
        for(int i = 1; i <= n; i++) {
            bit[i] += v[i - 1];
            int j = i + (i & -i);
            if(j <= n) bit[j] += bit[i];
        }
    }

    void update(int i, int x) {
        for(i++; i <= n; i += i & -i) bit[i] += x;
    }

    int pref(int i) {
        int ret = 0;
        for(i; i; i -= i & -i) ret += bit[i];
        return ret;
    }

    int query(int l, int r) {
        return pref(r + 1) - pref(l);
    }

    int upper_bound(int x) {
        int p = 0;
        for(int i = __lg(n); i + 1; i--) {
            if(p + (1 << i) <= n && bit[p + (1<<i)] <= x) x -= bit[p += (1<<i)];
        }
        return p;
    }
};