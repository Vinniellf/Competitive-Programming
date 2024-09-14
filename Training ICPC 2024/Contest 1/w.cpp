//Increasing Subsecuence
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

const int N = 1e4;
const ll MOD = 998244353LL;
const int INF = 1e9 + 5;

const char A = 'a';
const char ZERO = '0';
const char ENDL = '\n';

const string YES = "YES";
const string NO = "NO";

// Solucion O(n^2)
void solve1(){
    int n; cin>>n;
    vector<int> vec(n); 
    vector<int> d(n, 1);
    rep(i, n) cin>>vec[i];
    rep(i, n){
        rep(j, i){
            if(vec[i] > vec[j]) d[i] = max(d[i], d[j] + 1);
        }
    }
    int mx = d[0];
    for(int i = 1; i < n; i++) mx = max(mx, d[i]);
    cout<<mx;
}

//Solucion O(n^2) mas guardado de la subsecuancia
void solve2(){
    int n; cin>>n;
    vector<int> vec(n); 
    vector<int> d(n, 1), p(n, -1);
    rep(i, n) cin>>vec[i];
    rep(i, n){
        rep(j, i){
            if(vec[i] > vec[j] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
                p[i] = j;
            }
        }
    }

    int mx = d[0], p_final = 0;
    for(int i = 1; i < n; i++) {
        if(d[i] > mx){
            mx = d[i];
            p_final = i;
        }
    }

    vector<int> subseq;
    while(p_final != -1){
        subseq.push_back(vec[p_final]);
        p_final = p[p_final];
    }

    reverse(subseq.begin(), subseq.end());
    for(int num : subseq) cout<<num<<" ";
    cout<<ENDL;
    cout<<mx;
}

void solve3(){
    int n; cin>>n;
    vector<int> vec(n);
    rep(i, n) cin>>vec[i];
    vector<int> d(n + 1, INF);
    d[0] = -INF;
    int r, l, num;
    rep(i, n){
        r = 0, l = n;
        for(int j = 0; j < 35; j++){
            num = (r + l)/2;
            if(vec[i] > d[num]) r = num;
            else l = num;
        }
        d[l] = vec[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(d[i] == INF) break;
        ans++;
    }
    cout<<ans;
}




int main(){
  //freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    fastio;
    int t=1;
    //cin>>t;
    while(t--){
        solve3();
    }

    return 0;
}