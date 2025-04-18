#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const ll p1 = 31, p2 = 37;
const int maxN = 1505;

int N;
char S[maxN];
bool good[26];
ll pow2[maxN], h2[maxN];


void init(){
    pow2[0] = 1;
    h2[0] = 0;
    for(int i = 1; i <= maxN; i++){
        int c = (int) (S[i - 1] - 'a' + 1);
        pow2[i] = (pow2[i-1] * p2) % MOD;
        h2[i] = (h2[i-1] + c * pow2[i - 1]) % MOD;
    }
}

int main(){
    scanf(" %s", S);
    N = (int) strlen(S);
    string bits; cin>>bits;
    for(int i = 0; i < 26; i++) good[i] = bits[i] - '0';
    int k; cin>>k;
    init();

    vector<int> count(N + 1, 0);
    for(int i = 0; i < N; i++){
        count[i + 1] = count[i];
        if(!good[S[i] - 'a']) count[i + 1]++;
    }

    vector<pair<int, int>> ans;

    for(int r = 1; r <= N; r++){
        for(int l = 0; l < r; l++){
            if(count[r] - count[l] <= k) ans.push_back({((h2[r] - h2[l] + MOD) * pow2[N - l]) % MOD, l - r});
        }
    }
    int a = (ans.size() > 0 ? 1 : 0);
    sort(ans.begin(), ans.end());
    for(int i = 1; i < ans.size(); i++){
        if(ans[i] != ans[i - 1]) a++;
    }

    cout<<a;
}