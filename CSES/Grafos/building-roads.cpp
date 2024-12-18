#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;

// USO DE DFS para componentes
vector<vector<int>> g(maxN);
vector<vector<int>> comp;
bool used[maxN];

void dfs(int v, int j){
    for(int u : g[v]){
        if(!used[u]) {
            used[u] = true;
            comp[j].push_back(u);
            dfs(u, j);
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
    int index = 0;
    for(int i = 0; i < n; i++){
        if(!used[i]){
            used[i] = true;
            comp.emplace_back();
            comp[index].push_back(i);
            dfs(i, index);
            index++;
        }
    }

    cout<<comp.size() - 1<<endl;
    for(int i = 1; i < comp.size(); i++){
        cout<<comp[i - 1][0] + 1<<" "<<comp[i][0] + 1<<endl;
    }
    
    return 0;
}