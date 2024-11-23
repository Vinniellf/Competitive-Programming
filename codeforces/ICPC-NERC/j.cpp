#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1000003;
//const ll MOD2 = 911382323;
const ll p1 = 71, p2 = 97;
const ll maxN = 1e18;


void solve(){
    int n; cin>>n;
    char a; int num;
    int suma = 0;
    while(n--){
        cin>>a>>num;
        if(a == 'P') suma += num;
        else{
            if(num >= suma){
                if(num == suma) cout<<"NO\n";
                else cout<<"YES\n";
                suma = 0;
            } else {
                cout<<"NO\n";
                suma -= num;
            }
        }


    }
    

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    while(t--){solve();}
    return 0;
}