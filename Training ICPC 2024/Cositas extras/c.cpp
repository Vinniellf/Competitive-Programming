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

void solve(){
    int n; cin>>n;
    int ans = 7;
    int c = 0;
    int copia = n;
    bool ok = false;
    int ant;
    while(n > 0){
        int dig = n % 10;
        c++;
        if(c == 1){
            ant = dig;
            dig = dig - 7;
            if(dig < 0) dig += 10;
            ans = min(ans, dig);
        } else {
            if(dig == 0 and !ok) {n /= 10; continue;}
            if(!ok){
                if(dig == 8){
                    ans = min(ans, 1 + ant);
                }
                if(dig <= 7){
                    dig = 7 - dig;
                    if(dig > ant) dig++;
                    ans = min(ans, dig);
                }
            } else{
                if(dig <= 7){
                    dig = 7 - dig;
                    ans = min(ans, dig);
                }
            }
            ok = true;
        } 

        n /= 10;
    }

    cout<<ans<<endl;

   
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
