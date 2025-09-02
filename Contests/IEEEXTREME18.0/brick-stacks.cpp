#include<bits/stdc++.h>
using namespace std;

//principio de inclusion y exclusion

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll N = 1e18;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, index; cin>>n>>x;
    vector<int> vec(n);
    vector<vector<int>> res(n);
    multiset<int> myset, setans;
    unordered_map<int, int> m, masn;
    vector<int> out(n);
    for(int i = 0; i < n; i++) {cin>>vec[i]; myset.insert(vec[i]); setans.insert(vec[i]); m[vec[i]]++; masn[vec[i]]++;}
    int count;
    int ans = 0;
    while(!setans.empty()){
        ans++;
        auto it = setans.begin();
        setans.erase(it);
        count++;
        while(true){
            it = setans.lower_bound(*it + x);
            if(it == setans.end()) break;
            setans.erase(it);
        }
    }
    cout<<ans<<endl;

    while(!myset.empty()){
        count = 0;
        auto it = myset.begin();
        out[count] = *myset.begin();
        myset.erase(it);
        count++;
        while(true){
            it = myset.lower_bound(out[count - 1] + x);
            if(it == myset.end()) break;
            out[count] = *it;
            myset.erase(it);
            count++;
        }
        cout<<count<<" ";
        for(int i = count - 1; i >= 0; i--) cout<<out[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}