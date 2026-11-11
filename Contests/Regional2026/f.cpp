#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    vector<vector<int>> idx(n + 1);
    for(int i = 0;i < n; i++) {
        cin >> v[i];
    }

    vector<int> a;

    int c = 0;
    for(int i = 0; i < n; i++) {
        if(a.empty() || a.back() != v[i]) {
            idx[v[i]].push_back(c++);
            a.push_back(v[i]);
        }
    }
    
    int len = (int)a.size();
    int mn = 1e6;
    for(int i = 1; i <= n; i++) {
        int curr_ans = len - 1;
        for(int index : idx[i]) {
            if(index == 0 || index == (len - 1)) curr_ans -= 1; 
            else if(a[index + 1] != a[index - 1]) curr_ans -= 1;
            else curr_ans -= 2; 
        }

        mn = min(mn, curr_ans);
    }

    cout << max(0, mn) << endl;

}

int main(){ 
    solve();
    return 0;
}