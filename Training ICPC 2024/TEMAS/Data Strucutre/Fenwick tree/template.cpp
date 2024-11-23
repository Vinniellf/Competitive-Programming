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

ll sum(int r) {
    ll res = 0;
    while(r > 0) { 
        res += Bit[r];
        r -= r & -r;
    }
    return res;
}

ll sum(int l, int r) {k
    return sum(r) - sum(l - 1);
}


void add(int x, int delta) {
    while(x <= n){
        Bit[x] += delta;
        x += x & -x;
    }
}

void solve(){
    int test = 0;
    while(true){
        cin>>n; vector<int> vec(n + 1);
        if(n == 0) return;
        for(int i = 0; i <= n; i++) Bit[i] = 0;
        for(int i = 1; i <= n; i++){
            cin>>vec[i];
            add(i, vec[i]);
        }
        //bool ok = false;
        string s; int a, b;
        test++;
        cout<<"Case "<<test<<": \n";
        while(true){
            cin>>s;
            if(s[0] == 'E') {cout<<"\n"; break;}
            cin>>a>>b;
            if(s[0] == 'S'){
                add(a, b - vec[a]);
            } else{
                //if(!ok) {cout<<"Case "<<test<<": \n"; ok = true;}
                cout<<sum(a, b)<<endl;
            }


        }

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