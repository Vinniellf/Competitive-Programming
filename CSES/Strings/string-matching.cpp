#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const ll p1 = 37;
const int maxN = 1e6+5;

int N;
char S[maxN], T[maxN];
ll pow1[maxN], h1[maxN], h2[maxN];

void init(){
    pow1[0] = 1;
    h1[0] = (int) (S[0] - 'a' + 1);
    h2[0] = (int) (T[0] - 'a' + 1); 
    for(int i = 1; i < maxN; i++){
        int c1 = (int) (S[i] - 'a' + 1);
        int c2 = (int) (T[i] - 'a' + 1);
        pow1[i] = (pow1[i-1] * p1) % MOD;
        h1[i] = (h1[i-1] + c1 * pow1[i]) % MOD;
        h2[i] = (h2[i-1] + c2 * pow1[i]) % MOD;
    }
}

int main(){
    scanf(" %s", S);
    scanf(" %s", T);
    int s = (int) strlen(S);
    int t = (int) strlen(T);
    init();
    long long h_ans = h2[t - 1];
    //cout<<h1[s - 1]<<" "<<h2[t - 1];
    int ans = 0;
    for(int i = 0; i + t - 1 < s; i++){
        if((h_ans * pow1[i]) % MOD == (h1[i + t - 1] - (i == 0 ? 0 : h1[i - 1]) + MOD) % MOD) ans++;
    }
    cout<<ans;
}   