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

const double PI = 3.141592653;



void solve(){
    int ang, n; cin>>ang>>n;
    double factor = 1.0/tan((PI * ang) / 180.0);
    vector<pair<int, int>> vec(n);
    vector<pair<double, double>> ans(n);
    rep(i, n) cin>>vec[i].first>>vec[i].second;
    sort(all(vec));
    rep(i, n) {
        ans[i].first = vec[i].first;
        ans[i].second = vec[i].second * factor + vec[i].first;
    }
    double res = 0.0;
    double init = ans[0].first, last = ans[0].second;
    for(int i = 1; i < n; i++){
        if(ans[i].first > last){
            res += last - init;
            init = ans[i].first;
            last = ans[i].second;
            continue;
        }
        last = max(last, ans[i].second);
    }
    res += last - init;
    cout<<res;


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