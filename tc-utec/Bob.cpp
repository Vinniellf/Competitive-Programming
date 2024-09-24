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
const ll MOD = 1e9 + 7;
const int INF = 1e9;

const char A = 'a';
const char ZERO = '0';
const char ENDL = '\n';

const string YES = "YES";
const string NO = "NO";


void solve(){
    int r, c; cin>>r>>c;
    vector<vector<int>> vec_bit(26);
    vec_bit[0].push_back(0);

    for(int i = 1; i <= 25; i++){
        if(i - 2 >= 0){
            for(int j = 0; j < vec_bit[i - 2].size(); j++){
                vec_bit[i].push_back(vec_bit[i - 2][j] | (1 << i));
            }
        }
        if(i - 3 >= 0){
            for(int j = 0; j < vec_bit[i - 3].size(); j++){
                vec_bit[i].push_back(vec_bit[i - 3][j] | (1 << i));
            }
        }
    }

    int cant_mask = vec_bit[c].size();
    vector<int> vec_mask(cant_mask);
    for(int i = 0; i < cant_mask; i++) vec_mask[i] = vec_bit[c][i];  


    vector<vector<int>> dp(r, vector<int>(cant_mask, 0));
    //Inicializamos
    for(int i = 0; i < cant_mask; i++) dp[0][i] = 1;
    for(int i = 1; i < r; i++){
        for(int j = 0; j < cant_mask; j++){
            for(int k = 0; k < cant_mask; k++){
                if((vec_mask[j] & vec_mask[k]) == (1<<c)) dp[i][j] = (dp[i][j] + dp[i - 1][k])%MOD;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < cant_mask; i++) ans = (ans + dp[r - 1][i])%MOD;
    cout<<ans;
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