#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll MOD = 1000003;
//const ll MOD2 = 911382323;
const int INF = 1000000;
 
int dp[101][101][101];
 
void init(){
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            for(int k = 0; k <= 100; k++){
                dp[i][j][k] = INF;
            }
        }
    }
 
    vector<vector<int>> u(8, vector<int>(3));
    u[0][0] = 0, u[0][1] = 0, u[0][2] = 0;
    u[1][0] = 1, u[1][1] = 0, u[1][2] = 0;
    u[2][0] = 2, u[2][1] = 0, u[2][2] = 0;
    u[3][0] = 3, u[3][1] = 0, u[3][2] = 0;
    u[4][0] = 1, u[4][1] = 2, u[4][2] = 0;
    u[5][0] = 0, u[5][1] = 2, u[5][2] = 0;
    u[6][0] = 2, u[6][1] = 2, u[6][2] = 0;
    u[7][0] = 3, u[7][1] = 2, u[7][2] = 0;
 
    vector<vector<int>> d(5 , vector<int>(3));
    d[0][0] = 0, d[0][1] = 0, d[0][2] = 0;
    d[1][0] = 0, d[1][1] = 2, d[1][2] = 0;
    d[2][0] = 0, d[2][1] = 4, d[2][2] = 0;
    d[3][0] = 0, d[3][1] = 6, d[3][2] = 0;
    d[4][0] = 0, d[4][1] = 2, d[4][2] = 1;
 
    vector<vector<int>> c(9 , vector<int>(3));
    c[0][0] = 0, c[0][1] = 0, c[0][2] = 0;
    c[1][0] = 0, c[1][1] = 0, c[1][2] = 1;
    c[2][0] = 0, c[2][1] = 0, c[2][2] = 2;
    c[3][0] = 0, c[3][1] = 0, c[3][2] = 3;
    c[4][0] = 1, c[4][1] = 0, c[4][2] = 2;
    c[5][0] = 1, c[5][1] = 0, c[5][2] = 1;
    c[6][0] = 1, c[6][1] = 0, c[6][2] = 3;
    c[7][0] = 1, c[7][1] = 0, c[7][2] = 4;
    c[8][0] = 2, c[8][1] = 2, c[8][2] = 1;
 
    vector<vector<int>> m(4 , vector<int>(3));
    m[0][0] = 0, m[0][1] = 0, m[0][2] = 0;
    m[1][0] = 2, m[1][1] = 2, m[1][2] = 0;
    m[2][0] = 4, m[2][1] = 4, m[2][2] = 0;
    m[3][0] = 6, m[3][1] = 6, m[3][2] = 0;
    //
    set<vector<int>> conj;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 9; k++){
                for(int l = 0; l < 4; l++){
                    vector<int> ga(3);
                    ga[0] = u[i][0] + d[j][0] + c[k][0] + m[l][0];
                    ga[1] = u[i][1] + d[j][1] + c[k][1] + m[l][1];
                    ga[2] = u[i][2] + d[j][2] + c[k][2] + m[l][2];
                    if((ga[0] + ga[1] + ga[2]) == 0) continue;
                    conj.insert(ga);
                }
            }
        }
    }
 
    vector<vector<int>> v(conj.size(), vector<int>(3));
    int ind = 0;
    for (const auto& ve : conj) {
        v[ind] = ve;
        ind++;
    }
    
    dp[0][0][0] = 0;
 
    for(int i = 0; i < v.size(); i++){
        for(int x = 0; x <= 100; x++){
            for(int y = 0; y <= 100; y++){
                for(int z = 0; z <= 100; z++){
                    if((x + v[i][0] > 100) || (y + v[i][1] > 100) || (z + v[i][2]) > 100) break;
                    dp[x + v[i][0]][y + v[i][1]][z + v[i][2]] = min(dp[x][y][z] + 1, dp[x + v[i][0]][y + v[i][1]][z + v[i][2]]);
                }
            }
        }
    }
 
 
}
 
void solve(){
    int a, b, c; cin>>a>>b>>c;
    cout<<(dp[a][b][c] != INF ? dp[a][b][c] : -1);
    cout<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int t; cin>>t;
    while(t--){solve();}
    return 0;
}