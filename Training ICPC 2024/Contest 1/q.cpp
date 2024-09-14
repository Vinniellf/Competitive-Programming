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
const int MOD = 1e9 + 7;
const int INF = 1e8;

const char A = 'a';
const char ZERO = '0';
const char ENDL = '\n';

const string YES = "YES";
const string NO = "NO";

long long power(long long a, long long b)
{
    long long result = 1;
    while (b) {
        if (b & 1)
            result = (result * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return result;
}

int suma(int a, int b) {return (a + b)%MOD;}

void solve(){
    int n, m; cin>>n>>m;
    vector<int> vec(n + 2);
    vec[0] = -INF; vec[n + 1] = -INF;
    for(int i = 1; i <= n; i++) cin>>vec[i];

    const int M = m + 5;
    vector<vi> dp(n + 1, vi(M, 0));
    rep(i, 2) dp[1][i] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < M - 1; j++){
            if(j == 0) {
                dp[i][j] = suma(dp[i - 1][j], (2 * dp[i - 1][j + 1])%MOD); continue;
            }
            dp[i][j] = suma(dp[i - 1][j - 1], suma(dp[i - 1][j], dp[i - 1][j + 1]));
        }
    }

    vector<int> dist;
    vector<int> steps;
    int count = 1;
    rep(i, n + 2){
        if(vec[i] != 0) {
            steps.push_back(count);
            dist.push_back(vec[i]);
            count = 1;
            continue;
        }
        count++;
    }
    int ans = 0;

    if(dist.size() == 2){
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= m; j++){
                ans = (ans + dp[n - 1][abs(i - j)])%MOD;
            }
        }
        cout<<ans;
        return;
    }
    for(int i = 1; i < dist.size(); i++){
        if(abs(dist[i] - dist[i - 1]) > INF){
            ans = (ans * power(3, steps[i] - 1))%MOD;
        } else{
            ans = (ans * dp[steps[i]][abs(dist[i] - dist[i - 1])]);
        } 
    }

    cout<<ans;



    

}


int main(){
  freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    fastio;
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}