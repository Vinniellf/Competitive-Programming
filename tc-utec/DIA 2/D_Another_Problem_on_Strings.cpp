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
    int k;
    string s; 
    cin>>k>>s;
    vector<int> vec(1);
    ll n =  s.size();
    ll ans = 0LL;
    rep(i, n){
        if(s[i] == '1') vec.pb(i + 1);
    }
    vec.pb(n + 1);

    if(k > vec.size() - 2 ) {cout<<0; return;}
    if(k == 0) {
        REP(i, 1, vec.size()){
            ll d = vec[i] - vec[i - 1];
            ans += (d*d - d)/2;
        cout<<ans; return;
    }
    REP(i, 1, vec.size() - k){
        ans += (1LL) * (vec[i] - vec[i - 1]) * (vec[i + k] - vec[i + k - 1]);
    }
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