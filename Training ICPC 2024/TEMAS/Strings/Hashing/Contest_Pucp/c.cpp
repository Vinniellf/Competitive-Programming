#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const ll p1 = 41, p2 = 37;
const int maxN = 1e6+5;

int N;
char S[maxN];
ll pow1[maxN], pow2[maxN], h1[maxN], h2[maxN];

void init(){
    pow1[0] = pow2[0] = 1;
    h1[0] = h2[0] = 0;
    for(int i = 1; i < maxN; i++){
        int c = (int) (S[i - 1] - 'a' + 1);
        pow1[i] = (pow1[i-1] * p1) % MOD;
        pow2[i] = (pow2[i-1] * p2) % MOD;
        h1[i] = (h1[i-1] + c * pow1[i - 1]) % MOD;
        h2[i] = (h2[i-1] + c * pow2[i - 1]) % MOD;
    }
}

int main(){
    scanf(" %s", S);
    N = (int) strlen(S);
    init();

    string pat; cin>>pat;
    int len = pat.size();
    ll hash1 = (int)(pat[0] - 'a' + 1);

    for(int i = 1; i < len; i++){
        int c = (int)(pat[i] - 'a' + 1);
        hash1 = (hash1 + pow1[i] * c) % MOD;
    }

    int ans = 0;  
    for(int i = len; i <= N; i++){
        if((h1[i] - h1[i - len] + MOD) % MOD == hash1 * pow1[i - len] % MOD) ans++;
    }

    cout<<ans;


}