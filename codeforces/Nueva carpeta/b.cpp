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

void solve(){
    string s; cin>>s;
        bool ok = false;
        char ans = s[0];
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i - 1]){
                ans = s[i];
                ok = true;
                break;
            }

        }
        if(ok){
            cout<<ans<<ans<<endl;
            return;
        }

        if(s.size() >= 3){
            for(int i = 2; i < s.size(); i++){
                if(s[i] != s[i - 2]){
                    cout<<s[i - 2]<<s[i - 1]<<s[i]<<endl;
                    return;
                }
            }
            cout<<-1<<endl;
        } else{
            cout<<-1<<endl;
        }
}

int main(){

    fastio;
    cases{
        solve();
    }

    return 0;
}