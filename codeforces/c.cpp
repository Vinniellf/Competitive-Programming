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
    ll b, c, d; cin>>b>>c>>d;
    ll ans = 0LL;
    for(int i = 0; i <= 62; i++){
        ll mb = (b & (1LL<<i)), mc = (c & (1LL<<i)), md = (d & (1LL<<i));
        if(mb > 0 && mc > 0){
            if(md == 0) ans += (1LL<<i);
        } else if (mb > 0 && mc == 0){
            if(md == 0) {cout<<-1<<ENDL; return;}
        } else if(mb == 0 && mc > 0){
            if(md) {cout<<-1<<ENDL; return;}
        } else {
            if(md) ans += (1LL<<i);
        }
    }
    cout<<ans<<ENDL;
    
  
    
}


int main(){
  //freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    fastio;
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}