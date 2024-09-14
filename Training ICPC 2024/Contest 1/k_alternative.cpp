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

const ll MOD = 998244353LL;
const int INF = 1e9;
const int N = 1e6 + 5;

const char A = 'a';
const char ZERO = '0';
const char ENDL = '\n';

const string YES = "YES";
const string NO = "NO";

vector<int> a;
int n, x;
bool ready[N];
int value[N];

int dp(int x){
    if(x == 0) return 0;
    if(x < 0) return INF;
    if(ready[x]) return value[x];
    int mn = INF;
    rep(i, n) mn = min(mn, dp(x - a[i]) + 1);
    value[x] = mn;
    ready[x] = true;
    return mn;
}

void solve(){
    cin>>n>>x;
    vector<int> vec(n);
    rep(i, n) cin>>vec[i];
    a = vec;
    cout<<(dp(x) < INF? dp(x) : -1);
}


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}