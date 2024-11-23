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
    int n; cin>>n;
    vector<int> vec(n);
    rep(i, n) cin>>vec[i];
    bool corto = true;
    rep(i, n){
        if(vec[i] == 0) continue;
        if(vec[i] != i + 1){
            corto = false;
            break;
        }
    }
    if(corto) {
        rep(i, n) cout<<i+1<<" ";
        return;
    }

    bool corto = true;
    rep(i, n){
        if(vec[i] == 0) continue;
        if(vec[i] != n - i){
            corto = false;
            break;
        }
    }
    if(corto) {
        rep(i, n) cout<<n - i<<" ";
        return;
    }

    ///////
    

}


int main(){
  //freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    fastio;
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}