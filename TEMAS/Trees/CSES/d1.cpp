#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int MAXN = 2e5 + 5;
const int MAXD = 20;
int dp[MAXD][2];

void reset() {
    for(int i = 0; i < MAXD; i++) {
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
}


int dfs(int n, int x = 0, bool z = 1) {
    if(dp[x][z] != -1) return dp[x][z];

    dp[x][z] = 0;
    if(x == to_string(n).length()) {
        return dp[x][z];
    }

    int lim = 9;
    string num = to_string(n);
    if(z) lim = num[x] - '0';
    int a1 = 1, a2 = 0;
    for(int i = x + 1; i < num.length(); i++) {
        a2 *= 10;
        a1 *= 10;
        a2 += num[i] - '0';
    }
    a2++;

    dp[x][z] = 0;
    for(int i = 0; i <= lim; i++) {
        if(!z) {
            dp[x][z] += dfs(n, x + 1 , 0);
            dp[x][z] += i *a1;
        } else {
            dp[x][z] += dfs(n, x + 1 , i == lim);
            if(i == lim) dp[x][z] += i * a2;
            else dp[x][z] += i * a1;
        }
    }

    return dp[x][z];

}

void solve() {
    int k; cin >> k;
    int l = 1; int r = 9;
    int inf = 0;
    int d = 0;
    int res = 0;
    while(true) {
        d++;
        if(k >= 1 && k <= r * d) {
            inf += k / d;
            res = k % d;
            break;
        } else {
            inf += r;
            k -= r * d;
        }
        r *= 10;
    }
    reset();
    int ga = dfs(inf);
    string s = to_string(inf + 1);
    for(int i = 0; i < res; i++){
        ga += s[i] - '0';
    }
    cout << ga << endl;

}



signed main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}