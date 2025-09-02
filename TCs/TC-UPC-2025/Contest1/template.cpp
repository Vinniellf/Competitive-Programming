#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define PI 3.14159265359

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll MOD = 998244353LL;
const int INF = 1e9;
const int MAXN = 1e6 + 5;

vector<vi> grafo;
vector<int> visited;
bool ok = false;
vector<int> color;

void dfs(int nodoActual){
    for(int vecino : grafo[nodoActual]){
        if(visited[vecino]==0 && color[vecino] != color[nodoActual]){
            visited[vecino]++;
            color[nodoActual] = color[vecino];
            dfs(vecino);
        } else if(visited[vecino] == 1 && color[vecino] != color[nodoActual]) ok = true;
    }
}

void solve() {
    int n, m; cin >> n >> m;
    grafo.assign(n+1, vi());
    visited.assign(n+1, 0);
    color.assign(n+1, 0);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; 
        a--; b--;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    for(int i = 0; i < n; i++) {
        int c; cin >> c;
        color[i] = c; 
    }

    vector<int> visited1 = visited;
    vector<int> color1 = color;

    for(int i = 0; i < n; i++){
        if(ok) cout << i <<"-";
        visited = visited1;
        color = color1;
        visited[i]++;
        dfs(i);
    }

    if(ok) cout << "Yes";
    else cout << "No";


}

int main(){
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}