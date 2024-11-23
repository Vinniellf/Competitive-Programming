#include<bits/stdc++.h>
using namespace std;

//principio de inclusion y exclusion

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll N = 1e18;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<int, int> m;
    m[0]++;
    m[10] = 10;
    m[20] = 25;
    for(auto it : m) cout<<it.first<<" "<<it.second<<endl;
    m[0]--;
    for(auto it : m) cout<<it.first<<" "<<it.second<<endl;
    return 0;
}