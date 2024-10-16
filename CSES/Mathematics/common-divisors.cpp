#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


const int N = 1e6 + 5;

int ok[N];

signed main(){
    int n; cin>>n;
    int a;
    for(int i = 0; i < n; i++) {cin>>a; ok[a]++;}

    for(int i = N; i > 0; i--){
        int count = 0;
        for(int j = i; j <= N; j += i){
            if(ok[j]) count += ok[j];
        }
        if(count >= 2) {cout<<i; return 0;}
    }
    cout<<1;
    return 0;
}