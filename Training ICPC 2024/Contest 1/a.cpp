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
const string sp = " ";


void solve(){
    int n; cin>>n;
    if(n == 1) {cout<<n; return;}
    if(n == 4) {cout<<3<<sp<<1<<sp<<4<<sp<<2; return;}
    if(n < 5) {cout<<"NO SOLUTION"; return;}
    
    int r = 1, l = (n + 1)/2 + 1;
    for(int i = 1; i <= n; i++){
        if(i & 1) {cout<<r<<sp; r++;}
        else {cout<<l<<sp; l++;}
    }
    
    
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