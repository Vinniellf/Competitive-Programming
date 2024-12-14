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
const int maxN = 1e6;

int main(){
    fastio;
    int n; cin>>n;
    vector<double> vec(n);
    for(int i = 0; i < n; i++) cin>>vec[i];
    vector<double> pos(n + 1, 0.0), neg(n + 1, 0.0);
    double neu = 1.0;
    for(int i = 0; i < n; i++){
        vector<double> p(n + 1, 0.0), ne(n + 1, 0.0);
        double new_neu;
        for(int j = 1; j <= n; j++){
            if(pos[j] == 0.0) continue;
            p[j + 1] += vec[i] * pos[j];
            p[j - 1] += (1.0 - vec[i]) * pos[j];
        }

        for(int j = 1; j <= n; j++){
            if(neg[j] == 0.0) continue;
            ne[j + 1] += (1.0 - vec[i]) * neg[j];
            ne[j - 1] += (vec[i]) * neg[j];
        }

        p[1] += neu * vec[i];
        ne[1] += neu * (1.0 - vec[i]);

        neu = p[0] + ne[0];
        pos = p;
        neg = ne;
    }

    double ans = 0.0;
    for(int i = 1; i <= n; i++) ans += pos[i];
    cout<<setprecision(10)<<ans;

    return 0;
}