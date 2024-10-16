#include<bits/stdc++.h>
using namespace std;

// USO DE BFS con memorizacion de recorrido

int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};

signed main(){
    int n, m; cin>>n>>m;
    bool visited[n][m];
    int colored[n][m];
    pair<int, int> father[n][m];
    memset(visited, 0, sizeof(visited));
    memset(colored, -1, sizeof(colored));
    char in;    
    pair<int, int> a = {0, 0}, b = {0, 0};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>in;
            visited[i][j] = (in == '#'? 1 : 0);
            if(in == 'A') a = {i, j};
            if(in == 'B') b = {i, j};
        }
    }
    int color = 0;
    visited[a.first][a.second] = 1;
    colored[a.first][a.second] = color;
    father[a.first][a.second] = {-1, -1};
    queue<pair<int, int>> q;
    q.push({a.first, a.second});
    while(!q.empty()){
        for(int k = 0; k < 4; k++){
            int x1 = q.front().first + x[k], y1 = q.front().second + y[k];
            if(visited[x1][y1] || x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) continue;
            visited[x1][y1] = 1;
            colored[x1][y1] = colored[q.front().first][q.front().second] + 1;
            father[x1][y1] = {q.front().first, q.front().second};
            q.push({x1, y1});
        }
        q.pop();
    }
      
    if(visited[b.first][b.second]){
        cout<<"YES\n";
        cout<<colored[b.first][b.second]<<"\n";
        int x1 = b.first, y1 = b.second;
        string ans;
        for(int i = 0; i < colored[b.first][b.second]; i++){
            if(father[x1][y1].first - x1 == 1) ans += "U";
            if(father[x1][y1].first - x1 == -1) ans += "D";
            if(father[x1][y1].second - y1 == 1) ans += "L";
            if(father[x1][y1].second - y1 == -1) ans += "R";
            int x2 = father[x1][y1].first;
            int y2 = father[x1][y1].second;
            x1 = x2; y1 = y2;
        }
        reverse(ans.begin(), ans.end());
        cout<<ans;
    } else cout<<"NO";
    return 0;
}