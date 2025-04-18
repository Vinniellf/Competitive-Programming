//Solución con Hashing, pero vuela en tiempo.
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define REP(i,k,n) for (int i = k; i <n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second

typedef long long ll;

const ll MOD = 911382323LL;
const ll MOD1 = 1e9 + 7;
const ll p1 = 43, p2 = 47;
const int maxN = 1e6 + 5;
const ll factor = 1e9;

int N;
string S;
ll pow1[maxN], pow2[maxN];

int main(){
    fastio;
    cin>>S;
    N = S.size();
    //pow1[0] = pow2[0] = 1;
    pow1[0] = 1;
    for(int i = 1; i < maxN; i++){
        pow1[i] = (pow1[i-1] * p1) % MOD;
        //pow2[i] = (pow2[i-1] * p2) % MOD;
    }
    int k; cin>>k;
    unordered_map<long long, int> ok;
    string in;
    for(int i = 0; i < k; i++) {
        cin>>in; 
        ll has1 = 0, has2 = 0;
        for(int i = 1; i <= in.size(); i++){
            int c = (int) (in[i - 1] - 'a' + 1);
            has1 = (has1 + c * pow1[i]) % MOD;
            //has2 = (has2 + c * pow2[i]) % MOD;
        }

        //ll sol = has1 * factor + has2;
        //ok[sol]++;
        ok[has1]++;
    }

    vector<ll> dp(N + 1, 0); dp[N] = 1;
    for(int i = N - 1; i >= 0; i--){
        ll has1 = 0, has2 = 0;
        for(int j = i; j < N; j++){
            int letter = S[j] - 'a' + 1;
            has1 = (has1 + letter * pow1[j - i + 1]) % MOD;
            //has2 = (has2 + letter * pow2[j - i + 1]) % MOD;
            if(ok[has1]) dp[i] = (dp[i] + dp[j + 1]) % MOD1;
            //if(ok[has1 * factor + has2]) dp[i] = (dp[i] + dp[j + 1]) % MOD1;
        }

    }
    cout<<dp[0];
    return 0;
}