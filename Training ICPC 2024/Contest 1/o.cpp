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
const ll MOD = 1e9 + 7LL;
const int INF = 1e9;

const char A = 'a';
const char ZERO = '0';
const char ENDL = '\n';

const string YES = "YES";
const string NO = "NO";



void solve(){
    int n; cin>>n;
    vector<vi> dp(n + 1, vi(n + 1));
    vector<vi> visit(n + 1, vi(n + 1)); 
    char inp;
    rep(i, n) {
        rep(j, n) {
            cin>>inp;
            if(inp == '*') visit[i + 1][j + 1] = 1;
        }
    }

    REP(i, 1, n + 1) {
        REP(j, 1, n + 1) {
            if(visit[i][j]) continue;
            if(i == 1 and j ==1) {dp[i][j] = 1; continue;}    
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%MOD;

        }
    }

    cout<<dp[n][n];

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