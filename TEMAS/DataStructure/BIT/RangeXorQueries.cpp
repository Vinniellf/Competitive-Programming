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

const int N = 2e6 + 5;
int n;

ll Bit[N];

ll query(int r) {
    ll res = 0;
    while(r > 0) { 
        res ^= Bit[r];
        r -= r & -r;
    }
    return res;
}

ll query(int l, int r) {
    return query(r) ^ query(l - 1);
}


void add(int x, int delta) {
    while(x <= n){
        Bit[x] ^= delta;
        x += x & -x;
    }
}

void solve(){
    int q; cin>>n>>q;
    for(int i = 0; i < n; i++){
        int a; cin>>a;
        add(i + 1, a);
    }

    for(int i = 0; i < q; i++){
        int a, b; cin>>a>>b;
        cout<<query(a, b)<<endl;
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