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

const int N = 1e3 + 1;
const ll MOD = 1e9 + 7;
const int INF = 1e9;

const char A = 'a';
const char ZERO = '0';
const char ENDL = '\n';

const string YES = "YES";
const string NO = "NO";


void solve(){
    int n; cin>>n;
    vl vec(n);
    rep(i, n) cin>>vec[i];

    //Combinatoria;
    vector<vector<ll>> c(N, vector<ll>(N));
    c[0][0] = 1;

    REP(i, 1, N){
        rep(j, i + 1){
            if(j == 0 or j == i) c[i][j] = 1; 
            else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j])%MOD;
        }
    }
 
    ll ans = 1LL;
    ll suma = 0LL;
    rep(i, n) {
        suma += vec[i];
        ans = (ans * c[suma - 1][vec[i] - 1])%MOD;
    }
    cout<<ans;
    
    
    
}


int main(){
    //freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    fastio;
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }

    return 0;
}