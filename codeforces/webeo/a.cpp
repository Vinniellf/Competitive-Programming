#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define cases ll T=0;cin>>T;while(T--)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define REP(i,k,n) for (int i = k; i <n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define PI 3.14159265359

typedef long double ld;
typedef long long ll;

struct tupla{
    int l; 
    int r; 
    int index;
};

void solve(){
    int n; cin>>n;
    vector<tupla> l(n), r(n);
    vector<pair<int, int>> vec(n);
    set<int> ml, mr;
    vector<int> ans(n, 0);

    for(int i = 0; i < n; i++) {
        int a, b; cin>>a>>b;
        l[i] = {a, b, i};
        r[i] = {a, b, i};
        vec[i] = {a, b};
    }
    sort(r.begin(), r.end(), [](tupla& a, tupla& b) {
        if (a.r == b.r) {
            return a.l > b.l; 
        }
        return a.r < b.r;
    });
    
    sort(l.begin(), l.end(), [](tupla& a, tupla& b) {
        if (a.l == b.l) {
            return a.r > b.r; 
        }
        return a.l < b.l; 
    });

    mr.insert(l[0].r);
    for(int i = 1; i < n; i++){
        int num = l[i].r;
        auto it = mr.lower_bound(num);
        if(vec[l[i].index] == vec[l[i - 1].index]){
            ans[l[i].index] = ans[l[i - 1].index] = 0;
            mr.insert(num);
            continue;
        }
        
        if(it != mr.end()){
            ans[l[i].index] += *it - num;
        } 
        mr.insert(num);
    }

    ml.insert(r[n - 1].l);
    for(int i = n - 2; i >= 0; i--){
        int num = r[i].l;
        auto it = ml.upper_bound(num);
        if(vec[r[i].index] == vec[r[i + 1].index]){
            ans[r[i].index] = ans[r[i + 1].index] = 0;
            ml.insert(num);
            continue;
        }
        if(it != ml.begin()){
            it--;
            ans[r[i].index] += num - *it;
        } 
        ml.insert(num);
    }


    for(int i = 0; i < n; i++) cout<<ans[i]<<endl;
    
    return;
}

signed main(){
    fastio;
    cases{
        solve();
    }

    return 0;
}