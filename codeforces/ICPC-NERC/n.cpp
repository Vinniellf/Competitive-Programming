#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1000003;
//const ll MOD2 = 911382323;
const ll p1 = 71, p2 = 97;
const ll maxN = 1e18;


void solve(){
    string s; cin>>s;
    int a = s[0] - '0', b = s[2] - '0';
    int op = s[1] - 59;
    if(op == 1){
        if(a < b) {cout<<s<<endl; return;}
    } else if(op == 2){
        if(a == b) {cout<<s<<endl; return;}
    } else {
        if(a > b) {cout<<s<<endl; return;}
    }

    if(a < b) cout<<a<<"<"<<b;
    else if(a == b) cout<<a<<"="<<b;
    else cout<<a<<">"<<b;
    cout<<"\n";
    

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--){solve();}
    return 0;
}