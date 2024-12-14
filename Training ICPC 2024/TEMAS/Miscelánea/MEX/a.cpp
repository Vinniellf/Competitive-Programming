//https://codeforces.com/contest/1935/problem/B



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

void task(bool flag){
	if (flag)
		cout << "YES\n";
	else
		cout << "NO\n";
}

void solve(){
    int n; cin>>n;
    vector<int> ok(n + 1, 0);
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin>>vec[i];
        ok[vec[i]] = 1;
    }
    int mx;
    for(int i = 0; i <= n; i++){
        if(ok[i] == 0) {mx = i; break;}
    }

    if(mx == 0){
        cout<<2<<endl;
        cout<<1<<" "<<1<<endl;
        cout<<2<<" "<<n<<endl;
        return;
    }
    vector<int> ans(mx, 0);
    int count = 0;
    vector<int> lol(4, 0);
    lol[0] = 1;
    for(int i = 0; i < n; i++){
        if(vec[i] < mx){
            if(ans[vec[i]] == 0){
                ans[vec[i]] = 1;
                count++;
            }
            if(count == mx){
                for(int j = 0; j < mx; j++) ans[j] = 0;
                count = 0;
                if(lol[1] == 0) {lol[1] = i + 1; lol[2] = i + 2; continue;}
                if(lol[3] == 0) {lol[3] = n; break;}

            }
        }
    }

    for(int i = 0; i < 4; i++) {
        if(lol[i] == 0) {
            cout<<-1<<endl;
            return;
        }
    }
    cout<<2<<endl;
    cout<<lol[0]<<" "<<lol[1]<<endl;
    cout<<lol[2]<<" "<<lol[3]<<endl;
}

int main(){
    fastio;
    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}