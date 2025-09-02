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
    int n;
    ll r, l; cin>>n>>r>>l;
    vl vec(n);
    rep(i, n) cin>>vec[i];
    ll ans = 0LL;
    ll sum = 0LL;
    rep(i, n){k
        if(sum + vec[i] < r) {sum += vec[i];continue;}
        if(sum + vec[i]>= r and sum + vec[i] <= l){sum = 0LL; ans++;continue;}
        if(sum + vec[i] > l){
            if(vec[i] >= r and vec[i] <= l) {sum = 0LL; ans++;}
            if(vec[i] > l) sum = 0LL;
            if(vec[i] < r) sum = vec[i];
        }
    }

    cout<<ans<<ENDL;

    
}


int main(){
//  freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    fastio;
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}