#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const string ENDL = "\n";

ll dp[20][2000][2];
bool is_happy[2000];

void reset(){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 2000; j++){
            for(int k = 0; k < 2; k++){
                dp[i][j][k] = -1LL;
            }
        }
    }
}

ll dfs(ll num, int pos, int sum, bool z){
    if(dp[pos][sum][z] != -1) return dp[pos][sum][z];

    dp[pos][sum][z] = (is_happy[sum] == 1);
    if(pos == to_string(num).length()) {return dp[pos][sum][z];}

    int lim = 9;
    if(!z) lim = to_string(num)[pos] - '0';

    dp[pos][sum][z] = 0;
    for(int xth = 0; xth <= lim; xth++){
        if(z) dp[pos][sum][z] += dfs(num, pos + 1, sum + xth * xth, 1);
        else dp[pos][sum][z] += dfs(num, pos + 1, sum + xth * xth, xth < lim);
    }
    
    return dp[pos][sum][z];
}

int sum_dig(int num){
    int sum = 0;
    while(num > 0){
        sum += (num % 10) * (num % 10);
        num /= 10;
    }
    return sum;
}

void init(){
    for(int i = 0; i < 2000; i++) is_happy[i] = 0;
    is_happy[1] = 1;
    for(int i = 2; i < 2000; i++){
        map<int, int> ok;
        int n = i;  
        bool flag = true;
        while(sum_dig(n) != 1){
            if(ok[sum_dig(n)]) {flag = false; break;}
            ok[sum_dig(n)]++;
            n = sum_dig(n);
        }
        if(!flag) is_happy[i] = 0;
        else is_happy[i] = 1;
    }
}

signed main(){
    init();
    ll a, b; cin>>a>>b;
    a--;
    reset();
    ll total = dfs(b, 0, 0, 0);
    reset();
    total -= dfs(a, 0, 0, 0);
    cout<<total;
    return 0;
}