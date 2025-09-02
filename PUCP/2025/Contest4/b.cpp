#include <bits/stdc++.h>
using namespace std;
typedef long double ll;

signed main() {
    freopen("input.txt", "r", stdin);
    ll x, y;
    int cant;
    int cases = 0;
    while(cin >> x >> y >> cant) {
        bool ok = true;
        ll x_n, y_n;
        ll x_c = 0, y_c = 0;
        for(int i = 0; i < cant; i++) {
            x_n = x_c * x_c - y_c * y_c + x;
            y_n = 2 * x_c * y_c + y;
            if(x_n * x_n + y_n * y_n > 4) {ok = false; break;}
            x_c = x_n;
            y_c = y_n;
        }

        cout << "Case " << ++cases << ": ";
        if(ok)  cout << "IN" << endl;
        else  cout << "OUT" << endl;
        
        
    }
    return 0;
}