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
    int n, k, ga; cin>>n>>k;
    vector<vi> visit(2, vector<int>(1024));
    visit[0][0] = 1; visit[1][0] = 1;
    vector<map<int, int>> DP(1024);
    DP[0][0]++;
    
    rep(i, n){
        cin>>ga;
        rep(j, 1024){
            if(visit[0][j]){
                visit[1][j ^ ga] = 1;
                for(const auto& elem: DP[j]){
                    DP[j ^ ga][elem.first + 1]++;
                }
            }
        }   
        rep(j, 1024) visit[0][j] = visit[1][j];
    }

    int mx = -1;
    rep(i, 1024) {
        if(visit[1][i]) mx = i;
    }
    
    cout<< (DP[mx][k] > 0 ? mx : -1);
    
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