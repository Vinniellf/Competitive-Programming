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

int n; 
vector<long double> head(3000);
vector<vector<long double>> mat(3000, vector<long double>(3000));
vector<vector<bool>> touch(3000, vector<bool>(3000, false));

long double dp(int i, int cant){
    if(cant < 0) return 0.0L;
    if(touch[i][cant]) return mat[i][cant];
    mat[i][cant] = head[i]*dp(i - 1, cant - 1) + (1.0L - head[i])*dp(i - 1, cant);
    touch[i][cant] = true;
    return mat[i][cant];
}


void solve(){
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>head[i];
    for(int i = 1; i <= n; i++){
        long double suma = 1.0L;
        long double sello = 1.0L;
        for(int j = 1; j <= i; j++) {suma *= head[j]; sello *= (1.0L - head[j]);}
        mat[i][i] = suma;
        mat[i][0] = sello; 
        touch[i][i] = true;
        touch[i][0] = true;
    }
    long double ans = 0.0L;
    for(int i = (n + 1)/2; i <= n; i++) ans += dp(n, i);
    cout << fixed << setprecision(15) << ans << ENDL;
    
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