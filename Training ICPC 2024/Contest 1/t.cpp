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

const int N = 500 + 1;
const ll MOD = 998244353LL;
const int INF = 1e9;

const char A = 'a';
const char ZERO = '0';
const char ENDL = '\n';

const string YES = "YES";
const string NO = "NO";

vector<vector<int>> mat(N, vi(N, 0));
vector<vector<bool>> touch(N, vector<bool>(N, false));

int dp(int a, int b){
    if(touch[a][b]) return mat[a][b];
    touch[a][b] = true;
    int mn = INF;
    for(int i = 1; i <= a/2; i++) mn = min(mn, dp(i, b) + dp(a - i, b) + 1);
    for(int i = 1; i <= b/2; i++) mn = min(mn, dp(a, b - i) + dp(a, i) + 1);
    mat[a][b] = mn;
    return mn;
}

void solve(){
    int a, b; cin>>a>>b;
    for(int i = 1; i <N; i++) touch[i][i] = true;
    for(int i = 1; i <N; i++) {touch[1][i] = true; mat[1][i] = i - 1;}
    for(int i = 1; i <N; i++) {touch[i][1] = true; mat[i][1] = i - 1;}
    cout<<dp(a, b);
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