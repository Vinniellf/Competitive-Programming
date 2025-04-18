#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const ll MUL = 1e9;
const ll p1 = 41, p2 = 37;
const int maxN = 1505;

int N;
char S[maxN];
ll pow1[maxN], pow2[maxN], h1[maxN], h2[maxN];
int alpha[26];



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
    vector<pair<int, int>> ans;

    string good; cin>>good;
    int k; cin>>k;
    

    for(int i = 0; i < N; i++){
        int count = 0;
        for(int j = i; j < N; j++){
            if( good[S[j] - 'a'] == '0') count++;
            if(count > k) break;
            ll str1 = ((h1[j + 1] - h1[i] + MOD) % MOD) * (pow1[N - i]) % MOD;
            ll str2 = ((h2[j + 1] - h2[i] + MOD) % MOD) * (pow2[N - i]) % MOD;
            ans.push_back({str1, str2});
        }
    }

    int a = (ans.size() > 0 ? 1 : 0);
    sort(ans.begin(), ans.end());
    for(int i = 1; i < ans.size(); i++){
        if(ans[i] != ans[i - 1]) a++;
    }
    cout<<a;
}