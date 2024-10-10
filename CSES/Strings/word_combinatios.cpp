#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define REP(i,k,n) for (int i = k; i <n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second

const int MOD = 1e9 + 7;
const int N = 1e5 + 1;

int main(){
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    fastio;
    int k; string word; cin>>word; cin>>k;
    unordered_map<string, int> rev;
    string in;
    for(int i = 0; i < k; i++) {cin>>in; reverse(in.begin(), in.end()); rev[in]++;}
    vector<int> dp(N, 0); dp[0] = 1;
    string res;
    for(int i = 0; i < word.size(); i++){
        res = "";
        for(int j = i; j >= 0; j--){
            res += word[j];
            if(rev[res]) dp[i + 1] = (dp[i + 1] + dp[j])%MOD;
        }

    }
    cout<<dp[word.size()];
    return 0;
}