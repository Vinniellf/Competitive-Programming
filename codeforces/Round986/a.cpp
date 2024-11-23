#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1000003;
//const ll MOD2 = 911382323;
const ll p1 = 71, p2 = 97;
const int maxN = 1e5+1;


void solve(){
    int n, x, y; cin>>n>>x>>y;
    string s; cin>>s;
    int x0 = 0, y0 = 0;
    bool ok = false;
    for(int i = 0; i < 1000; i++){
        if(x0 == x && y0 == y){ok = true; break;}
        if(s[i % n] == 'N') y0 ++;
        if(s[i % n] == 'S') y0 --;
        if(s[i % n] == 'E') x0 ++;
        if(s[i % n] == 'W') x0 --;
    }

    if(!ok) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--){solve();}
    return 0;
}