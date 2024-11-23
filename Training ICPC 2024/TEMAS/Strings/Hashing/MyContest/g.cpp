#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 10000019;
const ll MOD2 = 911382323;
const ll p1 = 31, p2 = 37;
const int maxN = 1e5 + 1;

int N;
char S[maxN];
ll pow1[maxN], pow2[maxN], h1[maxN], h2[maxN];

void init(){
    pow1[0] = pow2[0] = 1;
    for(int i = 1; i < maxN; i++){
        pow2[i] = (pow2[i-1] * p2) % MOD2;
        pow1[i] = (pow1[i-1] * p1) % MOD;
    }
}

void Hash(){
    h1[0] = h2[0] = 0;
    for(int i = 1; i <= N; i++){
        int c = (int) (S[i - 1] - 'a' + 1);
        h2[i] = (h2[i-1] + c * pow2[i - 1]) % MOD2;
        h1[i] = (h1[i-1] + c * pow1[i - 1]) % MOD;
    }
}


void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>S[i];
    N = n;
    Hash();
    /*vector<ll> vec;*/
    unordered_set<ll> vec;
    
    for(int r = k; r <= N; r++){
        vec.insert(((((h1[r] - h1[r - k] + MOD) * pow1[N - r + k]) % MOD) * 1000000000 + ((h2[r] - h2[r - k] + MOD2) * pow2[N - r + k]) % MOD2));
    }

    /*sort(vec.begin(), vec.end());
    int ans = (vec.size() > 0 ? 1 : 0);
    for(int i = 1; i < vec.size(); i++) if(vec[i] != vec[i - 1]) ans++;*/
    cout<<vec.size()<<endl;

}

signed main(){
    init();
    int t; cin>>t;
    while(t--) solve();
}