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

const int mxN = 21;
const int mxS = (1<<20) + 1;
const ll MOD = 998244353LL;
const int INF = 1e9;

const char A = 'a';
const char ZERO = '0';
const char ENDL = '\n';

const string YES = "YES";
const string NO = "NO";


void solve(){
    int n; ll x;
    cin>>n>>x;
    vector<int> vec(n);
    rep(i, n) cin>>vec[i];

    vector<pair<int, int>> dp(1<<n, {n + 1, 0});
    dp[0] = {1, 0};
    for(int s = 1; s < (1<<n); s++){
        for(int j = 0; j <n; j++){
            if(s & (1<<j)){
                auto option = dp[s ^ (1<<j)];
                if(option.second + vec[j] <= x) option.second += vec[j];
                else{
                    option.first++;
                    option.second = vec[j];
                }
                dp[s] = min(dp[s], option);
            }
        }
    } 

    cout<<dp[(1<<n) - 1].first;
    
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