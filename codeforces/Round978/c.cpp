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

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int N = 5001;
const ll MOD = 998244353LL;
const int INF = 1e9;

const char A = 'a';
const char ZERO = '0';
const char ENDL = '\n';

const string YES = "YES";
const string NO = "NO";



void solve(){
    int n; cin>>n;
    vector<vector<char>> vec(2, vector<char>(n));
    rep(i, n) cin>>vec[0][i];
    rep(i, n) cin>>vec[1][i];
    vector<int> dp(n/3 + 1);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        int mx = -1;
        int ans = 0;
        int count = 0;
        if(vec[0][i * 3] == 'A') count++;
        if(vec[1][i * 3] == 'A') count++;
        if(vec[1][i*3 + 1] == 'A') count++;
        if(count > 1) ans++;
        count = 0;
        if(vec[0][i * 3 + 2] == 'A') count++;
        if(vec[1][i * 3 + 2] == 'A') count++;
        if(vec[0][i*3 + 1] == 'A') count++;
        if(count > 1) ans++;
        mx = max(mx, ans);

        ans = 0;
        count = 0;
        if(vec[0][i * 3] == 'A') count++;
        if(vec[1][i * 3] == 'A') count++;
        if(vec[0][i*3 + 1] == 'A') count++;
        if(count > 1) ans++;
        count = 0;
        if(vec[0][i * 3 + 2] == 'A') count++;
        if(vec[1][i * 3 + 2] == 'A') count++;
        if(vec[1][i*3 + 1] == 'A') count++;
        if(count > 1) ans++;
        mx = max(mx, ans);

        ans = 0;
        count = 0;
        if(vec[0][i * 3] == 'A') count++;
        if(vec[0][i * 3 + 1] == 'A') count++;
        if(vec[0][i*3 + 2] == 'A') count++;
        if(count > 1) ans++;
        count = 0;
        if(vec[1][i * 3 ] == 'A') count++;
        if(vec[1][i * 3 + 2] == 'A') count++;
        if(vec[1][i*3 + 1] == 'A') count++;
        if(count > 1) ans++;
        mx = max(mx, ans);

        dp[i + 1] = dp[i] + mx;

    }
    cout<<dp[n/3]<<ENDL;


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