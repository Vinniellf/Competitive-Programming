#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define cases ll T=0;cin>>T;while(T--)
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define PI 3.14159265359

typedef long double ld;
typedef long long ll;

void solve(){    
    int n; cin>>n;
    vector<vector<int>> m(n);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin>>a>>b;
        a--; b--;
        m[a].push_back(b);
        m[b].push_back(a);
    }

    vector<int> ans(n + 1);
    queue<int> q;
    vector<bool> used(n, false);
    vector<int> d(n, 0);
    q.push(0); used[0] = true; ans[0] = 2;
    int l = 4, r = 2 * n;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for (int u : m[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                if(d[u] % 2 == 0){ans[u] = l; l += 2;} 
                else {ans[u] = r; r -= 2;}
            }
        }
    }

    /*for(int i = 0; i < n; i++) cout<<d[i]<<" ";
    cout<<endl;*/


    for(int i = 0; i < n; i++){
        if(m[i].size() == 1){
            if(abs(ans[i] - ans[m[i][0]]) == 2){
                if(ans[m[i][0]] > ans[i]) ans[i]++;
                else ans[i]--;
            }
        }
    }


    for(int i = 0; i < n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return;
}

signed main(){
    fastio;
    cases{
        solve();
    }
    return 0;
}