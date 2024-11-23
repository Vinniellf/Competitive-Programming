#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 10000019;
const ll MOD2 = 911382323;
const ll p1 = 31, p2 = 37;
const int maxN = 1e5+5;

int N, M, k;
char S[maxN];
char P[maxN];
ll pow1[maxN], h1[maxN], h1p[maxN];

void init(){
    pow1[0] = 1;
    h1[0] = h1p[0] = 0;
    for(int i = 1; i < maxN; i++){
        int c = (int) (S[i - 1] - ' ' + 1);
        int p = (int) (P[i - 1] - ' ' + 1);
        pow1[i] = (pow1[i-1] * p1) % MOD;
        h1[i] = (h1[i-1] + c * pow1[i - 1]) % MOD;
        h1p[i] = (h1p[i-1] + p * pow1[i - 1]) % MOD;
    }
}

bool ok(int index){
    int ans = 0, len = index + 1; 
    int hash1 = h1p[len];
    for(int i = len; i <= N; i++){
        if((hash1 * pow1[i - len]) % MOD == (h1[i] - h1[i - len] + MOD) % MOD) ans++;
    }
    return ans >= k;
}

int main(){
    string a, b; 
    getline(cin, a); getline(cin, b);
    for(int i = 0; i < a.size(); i++) S[i] = a[i];
    for(int i = 0; i < b.size(); i++) P[i] = b[i];
    cin>>k;
    N = a.size(); M = b.size();
    init();

    int l = 0, r = M;
    for(int i = 0; i < 36; i++){
        int mid = (l + r)/2;
        if(ok(mid)) l = mid;
        else r = mid;
    }
    if(r == l) {cout<<"IMPOSSIBLE"; return 0;}
    for(int i = 0; i <= l; i++) cout<<P[i];
    //cout<<l<<" "<<r;
    return 0;
}