#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
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

const int N = 500001;
const ll MOD = 100000000 + 7;
const int INF = 1e9;

const char A = 'a';
const char ZERO = '0';
const char ENDL = '\n';

const string YES = "YES";
const string NO = "NO";

vector<ll> fibo(N);

void fibonaccio(){
    fibo[1] = 1;
    fibo[2] = 1;
    REP(i, 3, N) fibo[i] = (fibo [i - 1] + fibo [i - 2]) % MOD;
}

void solve(){
    int n;
    cin>>n;
    cout<<fibo[n]<<ENDL;

}


int main(){
//  freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    fastio;
    int t=1;
    cin>>t;
    fibonaccio();
    while(t--){
        solve();
    }

    return 0;
}