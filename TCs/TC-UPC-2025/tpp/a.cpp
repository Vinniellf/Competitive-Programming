#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAXD = 31;
int dp[MAXD][MAXD][2][MAXD];

void reset() {
    for(int i = 0; i < MAXD; i++) {
        for(int j = 0; j < MAXD; j++) {
            for(int k = 0; k < MAXD; k++) {
                dp[i][j][0][k] = -1;
                dp[i][j][1][k] = -1;
            }
        }
    }
}


int dfs(int n, int dig = 0, int count = 0, bool top = 1, int ok = 30) {
    if(dp[dig][count][top][ok] != -1) return dp[dig][count][top][ok];

    dp[dig][count][top][ok] = (count > 0);
    if(dig == to_string(n).length()) {
        return dp[dig][count][top][ok];
    }

    int lim = 9;
    if(top) lim = to_string(n)[dig] - '0';

    dp[dig][count][top][ok] = 0;
    for(int i = 0; i <= lim; i++) {
        if(!top) {
            dp[dig][count][top][ok] += dfs(n, dig + 1 , count + (i == 0 && dig != to_string(n).length() - 1 && dig > ok), 0, (ok == 30 && i != 0 ? dig : ok));
        } else {
            dp[dig][count][top][ok] += dfs(n, dig + 1 , count + (i == 0 && dig != to_string(n).length() - 1 && dig > ok), i == lim, (ok == 30 && i != 0 ? dig : ok));
        }
    }

    return dp[dig][count][top][ok];

}


void solve() { 
    int n; cin >> n;
    reset();
    cout << dfs(n);
}



signed main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}