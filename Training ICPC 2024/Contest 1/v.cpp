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

vector<vector<ll>> mat(N, vector<ll>(N, 0));
vector<vector<bool>> vis(N, vector<bool>(N, false));
vector<ll> vec(N);

ll dp(int l, int r, ll suma){
    if(vis[l][r]){
        return mat[l][r];
    }
    vis[l][r] = true;
    ll mx = max(suma - dp(l + 1, r, suma - vec[l]), suma - dp(l, r - 1, suma - vec[r]));
    mat[l][r] = mx;
    return mx;
}


void solve(){
    int n; cin>>n;
    ll suma = 0LL;
    rep(i, n) {cin>>vec[i]; suma += vec[i];}
    rep(i, n) {mat[i][i] = vec[i]; vis[i][i] = true;}
    cout<<dp(0, n - 1, suma);
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