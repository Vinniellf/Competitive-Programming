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
    int a, b, r, m; cin>>a>>b>>m>>r;
    vector<int> gaus;
    gaus.push_back(1);
    int val = 10;
    while(val % m != 1){
        gaus.push_back(val % m);
        val = (val * 10) % m;
    }

    vector<int> dp(m, 0);
    dp[0] = 1;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < gaus.size(); j++){
            for(int k = a; k <= b; k++){
                dp[(k * gaus[j]) % m] = 1;
            }
        }
    }
    
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