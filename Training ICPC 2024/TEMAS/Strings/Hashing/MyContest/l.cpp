#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 10000019;
const ll MOD2 = 911382323;
const ll p1 = 31, p2 = 37;
const int maxN = 8e3+5;

int N;
char S[maxN];
ll pow1[maxN], pow2[maxN], h1[maxN], h2[maxN];

void init(){
    pow1[0] = pow2[0] = 1;
    h1[0] = h2[0] = 0;
    for(int i = 1; i < maxN; i++){
        int c = (int) (S[i - 1] - 'a' + 1);
        pow2[i] = (pow2[i-1] * p2) % MOD2;
        pow1[i] = (pow1[i-1] * p1) % MOD;
        h2[i] = (h2[i-1] + c * pow2[i - 1]) % MOD2;
        h1[i] = (h1[i-1] + c * pow1[i - 1]) % MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin>>s;
    N = s.size();
    for(int i = 0 ; i < N; i++) S[i] = s[i];
    init();

    vector<pair<int, int>> ans;
    int solos = 0;

    for(int i = 0; i < N; i++){
        for(int len = 1; i + len <= N; len++){
            ll has = (h1[i + len] - h1[i] + MOD) % MOD;
            bool is_p = true;
            for(int j = i + len; j + len <= N; j += len){
                has = (has * pow1[len]) % MOD;
                ll has1 = (h1[j + len] - h1[j] + MOD) % MOD;
                if(has == has1){

                }
            }
            if(is_p){
            
                break;
            }
        }
    }

}

//paseo(walk) secuencia alternada
//ruta (trail) no repite aristas
//camino (path) no repite vertices ni aristas
//ciclo (cycle) ruta donde el primer y ultimo vertice son iguales