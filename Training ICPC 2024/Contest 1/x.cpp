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

struct Elemento{
    int lim;
    int sup;
    ll pes; 

    Elemento(int l, int s, ll p) : lim(l), sup(s), pes(p) {}

    bool operator<(const Elemento& otro) const{
        if (sup == otro.sup) {
            // Desempate por 'pes' cuando 'sup' es igual
            return pes > otro.pes;  // Cambia a 'pes < otro.pes' para invertir el criterio
        }
        return sup > otro.sup;
    }
};

void solve(){
    int n; cin>>n;
    priority_queue<Elemento> vec;
    int a, b, c;
    rep(i, n){
        cin>>a>>b>>c;
        vec.push(Elemento(a, b, c));
    }
    /*
    while(!vec.empty()){
        cout<<vec.top().lim<<" "<<vec.top().sup<<" "<<vec.top().pes;
        cout<<ENDL;
        vec.pop();
    }
    return;*/

    vector<pair<int, ll>> ans;
    ans.push_back({0, 0});
    int l, r, num;
    while(!vec.empty()){
        r = 0; l = ans.size();
        rep(i, 34){
            num = (l + r)/2;
            if(ans[num].first < vec.top().lim) r = num;
            else l = num;
        }
        ans.push_back({vec.top().sup, max(ans[r].second + vec.top().pes, ans[ans.size() - 1].second)});
        vec.pop();
    }
    /*
    rep(i, n + 1){
        cout<<ans[i].first<<" "<<ans[i].second;
        cout<<ENDL;
    }
    return;*/
    cout<<ans[n].second;
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