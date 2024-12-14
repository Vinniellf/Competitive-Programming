#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define cases ll T=0;cin>>T;while(T--)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define REP(i,k,n) for (int i = k; i <n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define PI 3.14159265359

typedef long double ld;
typedef long long ll;

const ll MOD = 998244353LL;
const int INF = 1e9;
const int maxN = 1e5 + 5;

vector<int> ans(maxN);
vector<int> con(maxN);

void solve(){
    int n, m; cin>>n>>m;
    vector<int> vec(m);
    for(int i = 0; i < m; i++) cin>>vec[i];
    sort(vec.begin(), vec.end());

    for(int i = 1; i <= n; i++) ans[i] = m;
    for(int i = 1; i <= n; i++){
        for(int j = i + i; j <= n; j += i){
            if(ans[j] == ans[i]) ans[j]--;
        }
    }

    for(int i = 1; i <= n; i++){
        if(ans[i] < 1) {
            cout<<-1<<endl;
            return;
        }
    }



    for(int i = 1; i <= n; i++) cout<<vec[ans[i] - 1]<<" ";
    cout<<endl;
    
}

int main(){

    fastio;
    cases{
        solve();
    }



    return 0;
}