//Solución con Trie.
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define REP(i,k,n) for (int i = k; i <n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define F first
#define S second

typedef long long ll;

const ll MOD = 1e9 + 7;
const int K = 26;
string S;
int N;

struct Vertex {
    int next[K];
    bool output = false;

    Vertex() {
        fill(begin(next), end(next), -1);
    }
};

vector<Vertex> trie(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].output = true;
}


int main(){
    fastio;
    cin>>S;
    N = S.size();
    int k; cin>>k;
    string in;
    for(int i = 0; i < k; i++) {cin>>in; add_string(in);}

    vector<ll> dp(N + 1, 0); dp[N] = 1;
    for(int i = N - 1; i >= 0; i--){
       int v = 0;
        for(int j = i; j < N; j++){
            int c = S[j] - 'a';
            if(trie[v].next[c] == -1) break;
            v = trie[v].next[c];
            if(trie[v].output) dp[i] = (dp[i] + dp[j + 1]) % MOD;
        }

    }
    cout<<dp[0];
    return 0;
}