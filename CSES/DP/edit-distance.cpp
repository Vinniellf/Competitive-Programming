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
    vector<vector<pair<int, string>>> DP(2, vector<pair<int, string>>(n));
    //Inicializamos
    
    
    rep(i, 2) rep(j, n) DP[i][j] = {0, ""};
    int mx;
    string mx_str;
 
    rep(i, m){
        mx = 0;
        mx_str = "";
        rep(j, n){
            if(t[i] == s[j]){
                DP[1][j] = make_pair(mx + 1, mx_str + t[i]);
            }
            if(mx < DP[0][j].first){
                mx = DP[0][j].first;
                mx_str = DP[0][j].second;
            }
            DP[0][j] = DP[1][j];
        }
    }

    int ans = 0;
    string ans_str = "";
    rep(i, n){
        if(ans < DP[1][i].first){
            ans = DP[1][i].first;
            ans_str = DP[1][i].second;
        }
    }

    cout<<t.size() - ans_str.size();

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