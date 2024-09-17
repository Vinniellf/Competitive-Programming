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

int n;
ll x;
vector<int> vec;
vector<int> memo((1<<20), INF);


void solve(){
    cin>>n>>x;
    vec.resize(n);
    rep(i, n) cin>>vec[i];
    vector<vector<pair<int, ll>>> dp(mxN, vector<pair<int, ll>>(mxS, {0, INF}));
    vector<int> elem_s(mxS);
    vector<ll> suma_s(mxS);

    int count;
    int suma;
    for(int s = 0; s < (1<<n); s++){
        count = 0;
        suma = 0;
        for(int j = 0; j < n; j++){
            if(s & (1<<j)){
                count++;
                suma += vec[j];
            }
            elem_s[s] = count;
            suma_s[s] = suma;
        }
    }

    

    

    
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