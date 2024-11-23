#include<bits/stdc++.h>
using namespace std;

//principio de inclusion y exclusion

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll N = 1e18;

int main(){
    ll n; ll k, in; 
    cin>>n>>k; //gaaaa
    unordered_map<ll, int> m;
    ll ans = 0LL;
    for(int i = 0; i < k; i++) {
        cin>>in;
        vector<pair<ll, int>> vec;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if(it->first * in > n || it->first % in == 0) continue;
            m[it->first * in] = m[it->first] + 1;
           //vec.push_back({it->first * in, m[it->first] + 1});
           ans += ((m[it->first] + 1) % 2 == 1? n/(it->first * in) : (-1)*(n/(it->first * in)));
        }
        /*
        for(int i = 0; i < vec.size(); i++) {
            m[vec[i].first] = vec[i].second;
            ans+= (vec[i].second % 2 == 1? n/(vec[i].first) : (-1)*(n/(vec[i].first)));
            
        }*/
        //vec.clear();
        m[in]++;
        ans += n/in;
    }

    cout<<ans<<"\n";
    return 0;
}