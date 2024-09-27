//https://atcoder.jp/contests/dp/tasks/dp_l
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

const int N = 5001;
const ll MOD = 998244353LL;
const int INF = 1e9;

const char A = 'a';
const char ZERO = '0';
const char ENDL = '\n';

const string YES = "YES";
const string NO = "NO";

vector<ll> vec(3000);
vector<vector<ll>> dp(3000, vector<ll>(3000, 0LL));
vector<vector<bool>> touch(3000, vector<bool>(3000, false));

ll max_pun(int l, int r, ll total){
    if(touch[l][r]) return dp[l][r];
    dp[l][r] = max(total - max_pun(l + 1, r, total - vec[l]), total - max_pun(l, r - 1, total - vec[r]));
    touch[l][r] = true;
    return dp[l][r];

}


void solve(){
    int n; cin>>n;
    ll suma = 0LL;
    rep(i, n) {cin>>vec[i]; suma += vec[i];}
    rep(i, n) {touch[i][i] = true; dp[i][i] = vec[i];}
    ll f = max_pun(0, n - 1, suma);
    ll s = suma - f;
    cout<<f - s;
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