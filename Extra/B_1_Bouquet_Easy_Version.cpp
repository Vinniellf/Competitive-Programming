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
    ll n, m; cin>>n>>m;
    int a;
    map<int, int> mp;
    set<int> st, sEnd;
    rep(i, n) {
        cin>>a;
        mp[a]++;
        st.insert(a);
    }

    vl copia(st.size());
    int counter = 0;
    for(set<int>::iterator it = st.begin(); it != st.end(); it++){
       copia[counter] = *it;
       counter++;
    }

    
    rep(i, st.size()){
        sEnd.insert(copia[i]*mp[copia[i]]);
        if(i != st.size() - 1 and copia[i + 1] - copia[i] <= 1) sEnd.insert(copia[i]*mp[copia[i]] + copia[i + 1]*mp[copia[i + 1]]);
    }

    for(set<int>::iterator it = sEnd.begin(); it != sEnd.end(); it++){
       cout<<*it<<" ";
    }
    cout<<ENDL;

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