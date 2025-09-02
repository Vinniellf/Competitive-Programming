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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s; cin>>s;
    N = s.size();
    vector<vector<int>> mat(100);
    for(int i = 0 ; i < N; i++) {
        S[i] = s[i];
        mat[S[i] - 'A' + 1].push_back(i + 1);
    }

    pow1[0] = 1;
    h1[0] = 0;
    for(int i = 1; i <= N; i++){
        int c = (int) (S[i - 1] - 'A' + 1);
        pow1[i] = (pow1[i-1] * p1) % MOD;
        h1[i] = (h1[i-1] + c * pow1[i - 1]) % MOD;
    }

    int q; cin>>q;
    ll has1;
    for(int i = 0; i < q; i++){
        string n_s; cin>>n_s;
        int len = n_s.size();
        has1 = (int)(n_s[0] - 'A' + 1); 
        for(int j = 1; j < len; j++){
            int c = (int) (n_s[j] - 'A' + 1);
            has1 = (has1 + c * pow1[j]) % MOD;
        }

        bool ok = false;
        int nodo = n_s[0] - 'A' + 1;
        for(int j = 0; j < mat[nodo].size(); j++){
            int init = mat[nodo][j];
            if(init - 1 + len >= N) break;
            if((has1 * pow1[init - 1] % MOD) == ((h1[init - 1 + len] - h1[init - 1] + MOD) % MOD)) {ok = true; break;}
        }
        
        if(ok) cout<<"Y\n";
        else cout<<"N\n";

    }
    return 0;
}