#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define PI 3.14159265359
#define int long long

void solve() {
    int n, m; cin >> n >> m;
    vector<int> v(n + 1, -1);
    
    rep(i, m) {
        char c;
        int val, num;
        cin >> c >> num;
        val = num;

        //factorizamos
        vector<int> ga;
        for(int i = 2; i * i <= val; i++) {
            if(val % i == 0) {
                ga.push_back(i);
            }
            while(val % i == 0) val /= i;
        }
        if(val > 1) ga.push_back(val);
        int len = (int) ga.size();
        
        if(c == '+') {
            if(num == 1) {
                if(v[1] == 1) cout << "Already on" << endl;
                else {cout << "Success" << endl; v[1] = 1;}
                continue;
            }
            bool ok = true;
            rep(i, len){
                if(v[ga[i]] != -1 && v[ga[i]] != num) {cout << "Conflict with " << v[ga[i]] << endl; ok = false; break;}
            }
            if(!ok) continue;

            ok = true;
            rep(i, len){
                if(v[ga[i]] == num) {cout << "Already on" << endl; ok = false; break;}
            }
            if(!ok) continue;
            
            for(auto u : ga) v[u] = num;
            cout << "Success" << endl;
            

        } else {
            
            if(num == 1) {
                if(v[1] == 1) {cout << "Success" << endl; v[1] = -1;}
                else cout << "Already off" << endl;
                continue;
            }
            bool ok = true;
            rep(i, len) {
                if(v[ga[i]] != num) {cout << "Already off" << endl; ok = false; break;}
            }
            if(!ok) continue;
            for(auto u : ga) v[u] = -1;
            cout << "Success" << endl;
        }

    }     
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();

    return 0;
}