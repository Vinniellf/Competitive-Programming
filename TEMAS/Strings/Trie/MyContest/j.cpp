#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 10000019;
const ll MOD2 = 911382323;
const ll p1 = 31, p2 = 37;
const int maxN = 1e3+5;

int N;
ll pow1[maxN], h1[maxN];
int ans[maxN];

void solve(int test){
    string s; cin>>s;
    N = s.size();
    memset(h1, 0, sizeof(h1));
    memset(ans, 0, sizeof(ans));
    
    h1[0] = 0;
    for(int i = 1; i <= N; i++){
        int c = (int) (s[i - 1] - 'a' + 1);
        h1[i] = (h1[i-1] + c * pow1[i - 1]) % MOD;
    }

    for(int i = 0; i < N; i++){
        for(int len = 1; len + i <= N; len++){
            int count = 1;
            ll has = ((h1[i + len] - h1[i] + MOD) * pow1[N -i]) % MOD;
            for(int j = i + len; j + len <= N; j += len){
                if(has == ((h1[j + len] - h1[j] + MOD) * pow1[N - j]) % MOD) {count++; continue;}
                break;
            }
            ans[count] = max(ans[count], count * len);
        }
    }

    cout<<"Case #"<<test<<":";
    for(int i = 1; i <= N; i++){
        cout<<" "<<ans[i];
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(ans, 0, sizeof(ans));
    pow1[0] = 1;
    for(int i = 1; i < maxN; i++){
        pow1[i] = (pow1[i-1] * p1) % MOD;
    }

    int t; cin>>t;
    for(int i = 0; i < t; i++){
        solve(i + 1);
    }

}