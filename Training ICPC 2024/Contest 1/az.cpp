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

const int mxN = 21;
const int mxS = (1<<20) + 1;
const ll MOD = 998244353LL;
const ll INF = 1e15;

const char A = 'a';
const char ZERO = '0';
const char ENDL = '\n';

const string YES = "YES";
const string NO = "NO";


void solve(){
    int n, k; cin>>n>>k;
    vector<ll> vec(n); rep(i, n) cin>>vec[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, INF));
    rep(i, k + 1) dp[0][i] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            ll mn = vec[i];
            for(int d = 0; i - d >= 0 && d <= j; d++){
                mn = min(mn, vec[i - d]);
                dp[i + 1][j] = min(dp[i + 1][j], dp[i - d][j - d] + mn*(d + 1));
            }
        }
    }

    cout<<dp[n][k]<<ENDL;

    

}


int main(){
    //freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    fastio;
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}