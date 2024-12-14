#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;

// USO DE BFS para encontrar el recorrido mas corto
vector<vector<int>> g(maxN);

signed main(){
    int n, m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int a, b; cin>>a>>b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    queue<int> q;
    vector<bool> used(n);
    vector<int> p(n);
    p[0] = -1; q.push(0); used[0] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u : g[v]){
            if(!used[u]){
                used[u] = true;
                p[u] = v;
                q.push(u); 
            }
        }
    }
    if(!used[n - 1]) {cout<<"IMPOSSIBLE"; return 0;}
    stack<int> ans; ans.push(n - 1);
    int end = n - 1;
    while(p[end] != -1){
        ans.push(p[end]);
        end = p[end];
    }

    cout<<ans.size()<<endl;
    while(!ans.empty()){
        cout<<ans.top() + 1<<" ";
        ans.pop();
    }
    
    return 0;
}