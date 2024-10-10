#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const string ENDL = "\n";
const ll MOD = 1e9 + 7;

ll dp[205][16500][2];
bool is_happy[16500];

void reset(){
    for(int i = 0; i < 205; i++){
        for(int j = 0; j < 16500; j++){
            for(int k = 0; k < 2; k++){
                dp[i][j][k] = -1LL;
            }
        }
    }
}

ll dfs(string num, int pos, int sum, bool z){
    if(dp[pos][sum][z] != -1) return dp[pos][sum][z];

    dp[pos][sum][z] = (is_happy[sum] == 1);
    if(pos == num.length()) {return dp[pos][sum][z];}

    int lim = 9;
    if(!z) lim = num[pos] - '0';

    dp[pos][sum][z] = 0LL;
    for(int xth = 0; xth <= lim; xth++){
        if(z) dp[pos][sum][z] = (dp[pos][sum][z] + dfs(num, pos + 1, sum + xth * xth, 1))%MOD;
        else dp[pos][sum][z] = (dp[pos][sum][z] + dfs(num, pos + 1, sum + xth * xth, xth < lim))%MOD;
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
    for(int i = 0; i < 16500; i++) is_happy[i] = 0;
    is_happy[1] = 1;
    for(int i = 2; i < 16500; i++){
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

void solve(){
    string a, b; cin>>a>>b;
    if(a[a.size() - 1] >= '1')  a[a.size() - 1]--;
    else{
        a[a.size() - 1] = '9';
        a[a.size() - 2]--;
    }
    reset();
    ll total = dfs(b, 0, 0, 0);
    reset();
    total -= dfs(a, 0, 0, 0);
    cout<<total<<ENDL;
}

signed main(){
    init();
    int t; cin>>t;
    while(t--){
        solve();
    }

}