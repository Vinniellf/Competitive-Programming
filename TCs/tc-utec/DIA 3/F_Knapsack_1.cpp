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

const int N = 1e4;
const ll MOD = 998244353LL;
const int INF = 1e9;

const char A = 'a';
const char ZERO = '0';
const char ENDL = '\n';

const string YES = "YES";
const string NO = "NO";


void solve(){
    int n, w; cin>>n>>w;
    vector<vector<ll>> vec(n, vector<ll>(2));
    rep(i, n) cin>>vec[i][0]>>vec[i][1];
    
    vector<vector<ll>> dp(n + 1, vector<ll>(w + 1, 0));
    rep(i, n){

        rep(j, w + 1){
            dp[i + 1][j] = dp[i][j];
            if(j - vec[i][0] < 0) continue;
            dp[i + 1][j] = max(dp[i][j], dp[i][j - vec[i][0]] + vec[i][1]);
        }
    }
    cout<<dp[n][w];
    
}


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }

    return 0;
}