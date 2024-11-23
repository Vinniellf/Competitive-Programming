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
    string s; cin>>s;
    vector<vector<int>> mat(s.size(), vector<int>(26, 0));
    vector<vector<int>> rev(s.size(), vector<int>(26, 0));
    for(int i = 0; i < s.size(); i++) {
        if(i != 0) {mat[i] = mat[i - 1]; rev[i] = rev[i - 1];}
        mat[i][s[i] - 'A'] |= 1; 
        rev[i][s[s.size() - 1 - i] - 'A'] |= 1;
    }
    for(int i = 1; i <= 26; i++){
        if(rev[i - 1] == mat[s.size() - 1 - i]) {cout<<s.size() - i; break;}

    }

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