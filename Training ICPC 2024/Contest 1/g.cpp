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

bool valid_mat[8][8];

int ans = 0;

void back(vector<int> vec){
    if(vec.size() == 8) {ans++; return;}
    int n = vec.size();
    rep(i, 8){
        if(!valid_mat[n][i]) continue;
        bool valid = true;
        rep(j, n){
            if(i == vec[j] or i == vec[j] + n - j or i == vec[j] - n + j) {valid = false; break;}
        }
        if(!valid) continue;
        vec.push_back(i);
        back(vec);
        vec.pop_back();
    }
    return;
}


void solve(){
  	char inp;
  	rep(i, 8) rep(j, 8) {cin>>inp; valid_mat[i][j] = (inp == '.'? true : false);}

    vector<int> vec;
    back(vec);
    cout<<ans;
    
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

    /*
    rep(i, 8) {
		rep(j, 8) {
			cout<<valid_mat[i][j]<<" ";
		}
		cout<<ENDL;
	}*/
}