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
    vi vec(3);
    int n, a, b, c; cin>>n>>vec[0]>>vec[1]>>vec[2];
    int mn = min(min(vec[0], vec[1]), vec[2]);
    vector<int> dp(n + 1);
    REP(i, mn,  n + 1){
        int mx = -1;
        rep(j, 3){
            if(i - vec[j] < 0) continue;
            if(i - vec[j] == 0) mx = max(mx, 0);
            if(dp[i - vec[j]] == 0) continue;
            mx = max(mx, dp[i - vec[j]]);
        }
        dp[i] = mx + 1;

    }
    cout<<dp[n];
    
}


int main(){
//  freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    fastio;
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }

    return 0;
}