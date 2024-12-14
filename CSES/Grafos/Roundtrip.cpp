#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;

// USO DE DFS usando colores
vector<vector<int>> g(maxN);
bool used[maxN];
vector<int> ans(maxN);
vector<int> p(maxN);
bool ok = false; 
int ind = -1;

void dfs(int v){
    for(int u : g[v]){
        if(used[u] && p[v] != u){
            ind = u; ok = true; p[u] = v;
        }
        if(!used[u]) {
            used[u] = true;
            p[u] = v;
            dfs(u);
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
            p[i] = -1;
            dfs(i);
        }
        if(ok) break;
    }
    if(!ok){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    cout<<ind + 1<<" ";
    int vertex = ind;
    while(p[vertex] != ind){
        cout<<p[vertex] + 1<<" ";
        vertex = p[vertex];
    }
    cout<<ind + 1<<" ";

    return 0;
}