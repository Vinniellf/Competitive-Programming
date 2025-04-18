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
    string s, t; cin>>s>>t;
    int n = s.size(), m = t.size();
    int DP[n + 1][m + 1];

    for(int i = 0; i <= n; i++){
        DP[i][0] = i;
    }
    for(int j = 0; j <= m; j++){
        DP[0][j] = j;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i - 1] == t[j - 1]) DP[i][j] = DP[i - 1][j - 1];
            else{
                DP[i][j] = min(min(DP[i - 1][j] + 1, DP[i][j - 1] + 1), DP[i - 1][j - 1] + 1);
            }
        }
    }
    cout<<DP[n][m];

}


int main(){
//  freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }

    return 0;
}