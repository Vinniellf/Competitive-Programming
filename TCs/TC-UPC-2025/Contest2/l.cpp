#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define REP(i,k,n) for (int i = k; i <n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

void solve(){
    ll v, e;
    cin>>v>>e;
    vector<vector<pair<ll,ll>>> grafo(v);
    ll a, b, w;
    rep(i,e){
        cin>>a>>b>>w;
        a--; b--;
        grafo[a].emplace_back(w,b);
        grafo[b].emplace_back(w,a);
    }


    int n = v;
    vector<ll> speed(n);
    rep(i, n) cin >> speed[i];
    const ll INF = 10000000000000;
    vector<vector<ll>> dist(n, vector<ll>(1001, INF));
 
    priority_queue<pair<ll, pair<ll,ll>>, vector<pair<ll, pair<ll,ll>>>, greater<>> q;
    q.push({0, {0, speed[0]}}); // coste = 0, nodo = 0, velocidad actual = speed[0]
    dist[0][speed[0]] = 0;
    ll currentNode, vecino, longitud, val1, val2, coste, s, new_speed;
    while(!q.empty()){
        s=q.top().S.S;
        currentNode = q.top().S.F;  
        coste = q.top().F;
        q.pop();
        for(auto &x: grafo[currentNode]){
            vecino = x.S;
            longitud = x.F; 
            new_speed = speed[currentNode];
            val1 = dist[currentNode][s]+longitud * new_speed;
            val2 = dist[currentNode][s]+longitud * s;
            if(val1 < dist[vecino][new_speed]){
                dist[vecino][new_speed]=val1;
                q.push(make_pair(val1, make_pair(vecino, new_speed)));
            }
            if(val2 < dist[vecino][s]){
                dist[vecino][s]=val2;
                q.push(make_pair(val1, make_pair(vecino, s)));
            }
        }
    }
    ll ans = INF;
    rep(i, 1001) ans = min(ans, dist[n - 1][i]);
    cout << ans <<endl;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}