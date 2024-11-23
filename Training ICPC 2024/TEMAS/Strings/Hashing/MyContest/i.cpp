#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
//const ll MOD = 1e9 + 7;
const ll MOD = 911382323LL;
const ll p1 = 61, p2 = 97;
const int maxN = 1000005;
const ll N = 1e9;

ll pow1[maxN], pow2[maxN], h1[maxN], h2[maxN];
ll powinv1[maxN], powinv2[maxN];

ll binpow(ll num, ll exp, ll m){
    ll res = 1;
    while(exp > 0){
        if((exp % 2) == 1) res = (res * num) % m;
        num = (num * num) % m;
        exp /= 2;
    }
    return res;
}

void init(){
    pow1[0] = pow2[0] = 1;
    for(int i = 1; i < maxN; i++){
        pow2[i] = (pow2[i-1] * p2) % MOD;
        pow1[i] = (pow1[i-1] * p1) % MOD;
        powinv1[i] = binpow(pow1[i], MOD - 2, MOD);
        powinv2[i] = binpow(pow2[i], MOD - 2, MOD);
    }
}

int main(){
    int n, k; cin>>n>>k;
    init();
    string ga; cin>>ga;
    h1[0] = h2[0] = 0;
    for(int i = 1; i <= k * n; i++){
        int c = (int) (ga[i - 1] - 'a' + 1);
        h2[i] = (h2[i-1] + c * pow2[i - 1]) % MOD;
        h1[i] = (h1[i-1] + c * pow1[i - 1]) % MOD;
    }

    int g; cin>>g;
    unordered_map<ll, int> mapeo;
    for(int i = 0; i < g; i++){
        string in; cin>>in;
        ll ha1 = (int) (in[0] - 'a' + 1), ha2 = (int) (in[0] - 'a' + 1);
        for(int j = 1; j < k; j++){
            int c = (int) (in[j] - 'a' + 1);
            ha2 = (ha2 + c * pow2[j]) % MOD;
            ha1 = (ha1 + c * pow1[j]) % MOD;
        }
        mapeo[ha1 * N  + ha2] = i + 1; 
    }

    vector<int> ans(n);
    ll has1, has2;
    for(int i = 1; i <= k; i++) {
        bool ok = true;
        for(int j = i; j + k <= k * n; j += k){
            has1 = (h1[j + k] - h1[j] + MOD) * powinv1[j] % MOD;
            has2 = (h2[j + k] - h2[j] + MOD) * powinv2[j] % MOD;
            ans[(j - 1) / k] = mapeo[has1 * N + has2];
            if(mapeo[has1 * N + has2] == 0) {ok = false; break;}
        }
        has1 = ((h1[n * k] - h1[n * k - (k - i)] + MOD) * powinv1[n * k - (k - i)] + (pow1[k - i] * h1[i])) % MOD;
        has2 = ((h2[n * k] - h2[n * k - (k - i)] + MOD) * powinv2[n * k - (k - i)] + (pow2[k - i] * h2[i])) % MOD;
        ans[n - 1] = mapeo[has1 * N + has2];
        if(mapeo[has1 * N + has2] == 0) ok = false;
        vector<int> lol = ans;
        sort(lol.begin(), lol.end());
        for(int i = 1; i < n; i++){
            if(lol[i] == lol[i - 1]) ok = false;
        }
        if(!ok) continue;
        cout<<"YES"<<endl;
        for(int l = 0; l < n; l++) cout<<ans[l]<<" ";
        return 0;
    }
    cout<<"NO";
    return 0;
}