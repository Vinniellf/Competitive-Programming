#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1000003;
//const ll MOD2 = 911382323;
const ll p1 = 71, p2 = 97;
const ll maxN = 1e18;


void solve(){
    int n; cin>>n;
    if(n % 2 == 1) {
        if(n < 27) cout<<-1<<endl;
        else{
            int a = 3;
            int ga = 0;
            for(int i = 1; i <= n; i++){
                if(i == 1 || i == 10 || i == 26) {cout<<1<<" "; continue;}
                if(i == 23 || i == 27) cout<<2<<" ";
                else{
                    cout<<a<<" ";
                    ga++;
                    if(ga == 2){ga = 0; a++;}
                }
            }
            cout<<endl;
        }

    }
    else{
        for(int i = 1; i <= n / 2; i++){
            cout<<i<<" "<<i<<" ";
        }
        cout<<endl;
    }
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