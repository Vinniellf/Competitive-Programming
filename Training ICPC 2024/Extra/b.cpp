#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

bool isprime(long long  num){
    if(num == 1) return false;
    for(int i = 2; i * i <= num; i++){
        if(num%i == 0) return false;
    }
    return true;
}

void solve(){
    long double a, b; cin>>a>>b;
    int ax = ceill(sqrtl(a) - 1);
    int bx = floorl(sqrtl(b) + 1);
    for(long long i = ax + 1; i < bx; i++){
        if(!isprime(i)) continue;
        cout<<i * i<<"\n";
        return;
    }
    cout<<-1<<"\n";
    return;

}

int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
}