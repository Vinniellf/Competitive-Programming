#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1000003;
//const ll MOD2 = 911382323;
const ll p1 = 71, p2 = 97;
const ll maxN = 1e18;


void solve(){
    int n; cin>>n;
    int ans = 0;
    int c1 = n, c2 = n, c3 = n;
    ans += n / 2;
    c2 -= 2 * (n / 2);
    c1 -= n / 2;
    ans += c1 / 3;
    c1 -= 3 * (c1 / 3);
    ans += (c1 + c2 + c3 + 1) / 2 ;
    cout<<ans;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t =1;
    while(t--){solve();}
    return 0;
}