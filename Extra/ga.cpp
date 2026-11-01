#include <bits/stdc++.h>
using namespace std;

bool check(vector<long long> &v, long long m, long long k){
    long long ck = 1, sump = 0;
    for(int i = 0; i < v.size(); i++){
        sump += v[i];
        if(sump > m){
            ck++;
        }
    }
    if(sump > m){
        ck++;
    }
    return ck <= k;
}

int main(){
    long long n, k;
    cin >> n >> k;
    vector<long long> x(n);
    long long suma = 0LL;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        suma += x[i];   
    }
    long long l = 0, r = suma, m;
    while(r-l > 1){
        m = (r+l)/2;
        if(check(x, m, k)) r = m;
        else l = m;
    }
    cout << r << endl;
}