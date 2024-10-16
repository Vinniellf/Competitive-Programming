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

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int N = 5001;
const ll MOD = 998244353LL;
const int INF = 1e9;

const char A = 'a';
const char ZERO = '0';
const char ENDL = '\n';

const string YES = "YES";
const string NO = "NO";



void solve(){
    ll n, x; cin>>n>>x;
    vector<ll> vec(n);
    rep(i, n) cin>>vec[i];
    ll ans = 0LL;
    while(!vec.empty()){
        ll mn = 1e9 + 1LL;
        vector<ll> now;
        sort(all(vec));
        for(ll i = vec.size() - 1; i >= max(0LL, (ll)vec.size() - x) ; i--){
            mn = min(mn, vec[i]);
            now.push_back(vec[i]);
        }
        for(int i = 0; i < now.size(); i++) vec.pop_back();
        for(int i = 0; i < now.size(); i++) if((now[i] - mn) != 0LL) vec.push_back(now[i] - mn);
        ans += mn;
    }
    cout<<ans<<ENDL;

}


int main(){
  freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    fastio;
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}