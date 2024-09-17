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

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int N = 1e5 + 1;
const int M = 101;
const int MOD = 1e9 + 7;
const int INF = 1e8;

const char A = 'a';
const char ZERO = '0';
const char ENDL = '\n';

const string YES = "YES";
const string NO = "NO";


void solve(){
    int n, m; cin>>n>>m;
    vector<int> vec(n); 
    rep(i, n) cin>>vec[i];
    vector<vector<int>> dp(N, vector<int>(M));
    if(vec[0] == 0) for(int i = 1; i <= m; i ++) dp[1][i] = 1;
    else dp[1][vec[0]] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= m; j++){
            if(vec[i - 1] != 0 && vec[i - 1] != j) continue;
            for(int k = j - 1; k <= j + 1; k++){
                if(k >= 1 && k <= m) dp[i][j] = (dp[i][j] + dp[i - 1][k])%MOD;
            }
        }
       
    }
    int ans = 0;
    for(int i = 1; i <= m; i++){
        ans = (ans + dp[n][i])%MOD;
    }
    cout<<ans;
}


int main(){
  //freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    fastio;
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}