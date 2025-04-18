#include <bits/stdc++.h>


using namespace std;
typedef unsigned long long ll;
const ll MOD = 10000019;
const ll MOD2 = 911382323;
const ll p1 = 31, p2 = 37;
const int maxN = 300005;

int N;
char S[maxN];
bool good[26];
ll pow1[maxN], pow2[maxN], h1[maxN], h2[maxN];


void init(){
    pow1[0] = pow2[0] = 1;
    h1[0] = h2[0] = 0;
    for(int i = 1; i <= maxN; i++){
        int c = (int) (S[i - 1] - 'a' + 1);
        pow2[i] = (pow2[i-1] * p2) % MOD2;
        pow1[i] = (pow1[i-1] * p1) % MOD;
        h2[i] = (h2[i-1] + c * pow2[i - 1]) % MOD2;
        h1[i] = (h1[i-1] + c * pow1[i - 1]) % MOD;
    }
}

int main(){
    scanf(" %s", S);
    N = (int) strlen(S);
    int q; cin>>q;
    init();

    int r, l;

    for(int i = 0; i < q; i++){
        cin>>l>>r;
        cout<<((h1[r] - h1[l] + MOD) * pow1[N - l]) % MOD<<((h2[r] - h2[l] + MOD2) * pow2[N - l]) % MOD2<<endl;
    }

}