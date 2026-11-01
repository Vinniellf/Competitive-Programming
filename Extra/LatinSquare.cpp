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

const int maxN = 501;

int mat[maxN][maxN];
int c[maxN][maxN], r[maxN][maxN];

void ans(int N) {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << "*" << endl;
    return;
}


void solve(){
    int N, T; cin >> N >> T;

    vector<int> col(N + 1);
    vector<int> row(N + 1);

    for(int i = 0; i < T; i++) {
        char c;
        int u, v;
        cin >> c >> u >> v;
        if(c == 'C') swap(col[u], col[v]);
        if(c == 'R') swap(row[u], row[v]);
    }    

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int val = -1;
            for(int k = 1; k <= N; k++) {
                if(r[i][k] == 0 && c[j][k] == 0) { 
                    val = k; 
                    r[i][val] = 1;
                    c[i][val] = 1;
                    mat[i][j] = val;
                    break;
                }
            }
            if(val == -1) {
                ans(N);
                cout << "**" << endl; return;
            }
            

            int a = i;
            int b = j;
           
            while(i != row[a] && j != col[b]) {
                a = row[a];
                b = col[b];
                if(r[a][val] == 1 || c[b][val] == 1) {
                    ans(N);
                    cout << "*" << endl; return;
                }
                mat[a][b] = val;
                r[a][val] = 1;
                c[b][val] = 1;
            }

        }
    }


    ans(N);
    return;
}


int main(){
    fastio;
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }

    return 0;
}