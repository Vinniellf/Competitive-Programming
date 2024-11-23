#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 500009;


void solve(){
    int n, k; cin>>n>>k;
    vector<int> count(maxN, 0);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){
            int a; cin>>a;
            count[a]++;
        }
    }

    int a = 0, b = 0, c = 0;
    for(int i = 1; i < maxN; i++){
        if(count[i] == 1) a++;
        if(count[i] == 2) b++;
        if(count[i] == 3) c++;
    }

    if(k <= c) {cout<<k; return;}
    k -= c;
    if(k <= b) {cout<<2 * k + c; return;}
    k -= b;
    cout<<c + 2 * b + 3 * k;
    
    return ;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    while(t--){solve();}
    return 0;
}