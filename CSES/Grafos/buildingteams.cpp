#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;

// USO DE DFS usando colores
vector<vector<int>> g(maxN);
bool used[maxN];
vector<int> ans(maxN);

void dfs(int v, int color){
    for(int u : g[v]){
        if(!used[u]) {
            used[u] = true;
            ans[u] = (color == 1? 2 : 1);
            dfs(u, (color == 1? 2 : 1));
        }
    }
}

signed main(){
    int n, m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int a, b; cin>>a>>b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    for(int i = 0; i < n; i++){
        if(!used[i]){
            used[i] = true;
            dfs(i, 1);
            ans[i] = 1;
        }
    }

    bool ok = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < g[i].size(); j++){
            if(ans[g[i][j]] == ans[i]){
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    }

    for(int i = 0; i < n; i++) cout<<ans[i]<<" ";
    
    return 0;
}