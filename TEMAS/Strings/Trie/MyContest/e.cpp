#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1000003;
//const ll MOD2 = 911382323;
const ll p1 = 71, p2 = 97;
const int maxN = 1e5+1;

int N;
char S[maxN];
ll pow1[maxN], pow2[maxN], h1[maxN], h2[maxN];

void init(){
    pow1[0] = pow2[0] = 1;
    h1[0] = h2[0] = 0;
    for(int i = 1; i < maxN; i++){
        int c = (int) (S[i - 1] - 'A' + 1);
        pow2[i] = (pow2[i-1] * p2) % MOD;
        pow1[i] = (pow1[i-1] * p1) % MOD;
        h2[i] = (h2[i-1] + c * pow2[i - 1]) % MOD;
        h1[i] = (h1[i-1] + c * pow1[i - 1]) % MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s; cin>>s;
    N = s.size();
    for(int i = 0 ; i < N; i++) S[i] = s[i];
    init();

    int q; cin>>q;
    ll has1, has2;
    for(int i = 0; i < q; i++){
        string n_s; cin>>n_s;
        int len = n_s.size();
        has1 = has2 = (int)(n_s[0] - 'A' + 1); 
        for(int j = 1; j < len; j++){
            int c = (int) (n_s[j] - 'A' + 1);
            has1 = (has1 + c * pow1[j]) % MOD;
            has2 = (has2 + c * pow2[j]) % MOD;
        }
        //cout<<has1<<" "<<h1[len]<<endl;
        //cout<<has2<<" "<<h2[len]<<endl;
        bool ok = false;
        for(int j = len; j <= N; j++){
            if((has1 * pow1[j - len] % MOD) == ((h1[j] - h1[j - len] + MOD) % MOD) && (has2 * pow2[j - len]) % MOD == ((h2[j] - h2[j - len] + MOD) % MOD)) {ok = true; break;}
        }
        if(ok) cout<<"Y\n";
        else cout<<"N\n";

    }
    return 0;
}