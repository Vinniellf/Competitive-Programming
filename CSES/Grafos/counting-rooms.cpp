#include<bits/stdc++.h>
using namespace std;

// USO DE BFS

int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};


signed main(){
    int n, m; cin>>n>>m;
    bool visited[n][m];
    memset(visited, 0, sizeof(visited));
    char in;    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>in;
            visited[i][j] = (in == '#'? 1 : 0);
        }
    }
    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visited[i][j]) continue;
            visited[i][j] = 1;
            ans++;
            queue<pair<int, int>> q;
            q.push({i, j});
            while(!q.empty()){
                for(int k = 0; k < 4; k++){
                    int x1 = q.front().first + x[k], y1 = q.front().second + y[k];
                    if(visited[x1][y1] || x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) continue;
                    visited[x1][y1] = 1;
                    q.push({x1, y1});
                }
                q.pop();
            }
        }
    }
    cout<<ans;
    return 0;
}