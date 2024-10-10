#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[100][100][2][2];

const string ENDL = "\n";

void reset(){
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            for(int k = 0; k < 2; k++){
                dp[i][j][k][0] = -1LL;
                dp[i][j][k][1] = -1LL;
            }
        }
    }

}

ll dfs(ll num, int x, int y, bool ok, bool z){
    if(dp[x][y][ok][z] != -1) return dp[x][y][ok][z];

    dp[x][y][ok][z] = (ok == 1);
    if(x == to_string(num).length()) return dp[x][y][ok][z];

    int lim = 9;
    if(!z){
        lim = to_string(num)[x] - '0';
    }

    dp[x][y][ok][z] = 0LL;
    for(int xth = 0; xth <= lim; xth++){
        if(z){
            dp[x][y][ok][z] += dfs(num, x + 1, (y == 11 && xth == 0? 11: xth), (xth == y || ok), 1);
        } else{
            //cout<<num<<" "<<x + 1<<" "<<(y == 11 && xth == 0? 11: xth)<<" "<<(xth == y || ok)<<" "<<(xth < lim)<<ENDL;
            dp[x][y][ok][z] += dfs(num, x + 1, (y == 11 && xth == 0? 11: xth), (xth == y || ok), xth < lim);
        }
    }
    return dp[x][y][ok][z];
}

signed main(){
    ll a, b; cin>>a>>b;
    a--;
    reset();
    ll total = b - dfs(b, 0, 11, 0, 0);
    reset();
    total = total - a + dfs(a, 0, 11, 0, 0);
    cout<<total;
    return 0;
}
