#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define F first
#define S second

typedef long double ld;
typedef long long ll;

const int N = 2e5 + 5;
int n;

ll Bit[N];

ll sum(int r) {
    ll res = 0;
    while(r > 0) { 
        res += Bit[r];
        r -= r & -r;
    }
    return res;
}

ll sum(int l, int r) {
    return sum(r) - sum(l - 1);
}


void add(int x, int delta) {
    while(x <= n){
        Bit[x] += delta;
        x += x & -x;
    }
}

void solve(){
    int q; cin>>n>>q;
    vector<long long> vec(n);
    for(int i = 0; i < n; i++){
        cin>>vec[i];
        add(i + 1, vec[i]);
    }

    for(int i = 0; i < q; i++){
        int a, b;
        cin>>a>>b;
        cout<<sum(a, b)<<endl;
    }

}


int main(){
//  freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    fastio;
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }

    return 0;
}