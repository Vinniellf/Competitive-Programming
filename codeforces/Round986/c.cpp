#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1000003;
//const ll MOD2 = 911382323;
const ll p1 = 71, p2 = 97;
const int maxN = 1e5+1;


void solve(){
    int n, m, k; cin>>n>>m>>k;
    vector<int> vec(n + 1, 0);
    for(int i = 1; i <= n; i++) cin>>vec[i];

    vector<int> pf(n + 1), suf(n + 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--){solve();}
    return 0;
}