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

int ans = 0;
vector<vector<int>> mat(9, vi(9, 0));
string s;

void f(int x, int y, int count){
    if(x == 7 and y == 1){
        if(count == 49) ans++;
        return;
    }
    if(mat[x + 1][y] == mat[x - 1][y] && mat[x][y + 1] == mat[x][y - 1] && mat[x + 1][y] != mat[x][y - 1]) return;

    mat[x][y] = 1;
    if(s[count - 1] == '?'){
        if(!mat[x + 1][y]) f(x + 1, y, count + 1);
        if(!mat[x - 1][y]) f(x - 1, y, count + 1);
        if(!mat[x][y + 1]) f(x, y + 1, count + 1);
        if(!mat[x][y - 1]) f(x, y - 1, count + 1);
    } else {
        if(!mat[x + 1][y] && s[count - 1] == 'D') f(x + 1, y, count + 1);
        if(!mat[x - 1][y] && s[count - 1] == 'U') f(x - 1, y, count + 1);
        if(!mat[x][y + 1] && s[count - 1] == 'R') f(x, y + 1, count + 1);
        if(!mat[x][y - 1] && s[count - 1] == 'L') f(x, y - 1, count + 1);
    }
    mat[x][y] = 0;
    return; 
}


void solve(){
    cin >> s;
    rep(i, 9){
        mat[0][i] = 1; mat[i][0] = 1; mat[8][i] = 1; mat[i][8] = 1;
    }
    
    f(1, 1, 1);
    cout<<ans;
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
