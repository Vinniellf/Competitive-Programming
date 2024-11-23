#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1000003;
//const ll MOD2 = 911382323;
const ll p1 = 71, p2 = 97;
const ll maxN = 1e18;


void solve(){
    ll n, b, c; cin>>n>>b>>c;
    if(b == 0){
        if(n > c + 2) {cout<<-1<<endl; return;}
        else if(n - c == 1 || n - c == 2) {cout<<n - 1<<endl; return;}
    }
    if(c >= n) {cout<<n<<endl; return;}
    else if(n - c == 1) {cout<<c<<endl; return;}

    ll l = 0, r = min(n, (maxN - c) / b + 1);
    for(int i = 0; i < 64; i++){
        ll mid = (l + r) / 2;
        if(n - 1 >= c + b * mid) l = mid;
        else r = mid;
    }

    cout<<n - 1 - l<<endl;



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--){solve();}
    return 0;
}