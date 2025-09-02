#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 911382323;
//const ll MOD2 = 911382323;
const ll p1 = 31, p2 = 37;
const int maxN = 5000005;

int N;
char S[maxN];
ll pow1[maxN], pow2[maxN], h1[maxN], h2[maxN];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin>>s;
    N = s.size();
    for(int i = 0 ; i < N; i++) S[i] = s[i];
    
    pow1[0] = pow2[0] = 1;
    h1[0] = h2[0] = 0;
    for(int i = 1; i < maxN; i++){
        int c = (int) (S[i - 1] - 'a' + 1);
        pow2[i] = (pow2[i-1] * p2) % MOD;
        pow1[i] = (pow1[i-1] * p1) % MOD;
        h2[i] = (h2[i-1] + c * pow2[i - 1]) % MOD;
        h1[i] = (h1[i-1] + c * pow1[i - 1]) % MOD;
    }

    int q, len; cin>>q;
    for(int i = 0; i < q; i++){
        cin>>len;

        int l = 0, r = min(len, N - len) + 1;
        for(int j = 0; j <= 21; j++){
            if(r - l == 1) break;
            int mid = (r + l) / 2;
            ll has1_a = ((h1[mid] - h1[0] + MOD) * pow1[N]) % MOD;
            ll has1_b = ((h1[len + mid] - h1[len] + MOD) * pow1[N - len]) % MOD;
            
            ll has2_a = ((h2[mid] - h2[0] + MOD) * pow2[N]) % MOD;
            ll has2_b = ((h2[len + mid] - h2[len] + MOD) * pow2[N - len]) % MOD;
            if(has1_a == has1_b && has2_a == has2_b) l = mid;
            else r = mid;
        }

        printf("%d\n", l);
    }   

}