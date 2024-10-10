#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1000000;
const ll MOD = 1e9 + 7;

int main(){
    int t; cin>>t;
    vector<ll> join(N), sep(N);
    join[0] = 1; sep[0] = 1;
    for(int i = 1; i < N; i++){
        join[i] = (2 * join[i - 1] + sep[i - 1])%MOD;
        sep[i] = (4 * sep[i - 1] + join[i - 1])%MOD;
    }

    int n;
    while (t--)
    {
        cin>>n;
        cout<<(sep[n - 1] + join[n - 1])%MOD<<"\n";
    }
    
    return 0;
}

