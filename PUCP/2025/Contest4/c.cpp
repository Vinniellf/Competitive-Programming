#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main() {
    vector<vector<string>> vec(2, vector<string>(3));
    vector<vector<ll>> v(2, vector<ll>(3));
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if(j == 2) getline(cin, vec[i][j]);
            else getline(cin, vec[i][j], ':');
            v[i][j] = stoi(vec[i][j]);
        }
    }
    
    ll seg1 = v[0][0] * 3600 + v[0][1] * 60 + v[0][2];
    ll seg2 = v[1][0] * 3600 + v[1][1] * 60 + v[1][2];
    ll diff = seg2 - seg1;
    if (diff <= 0) diff += 24 * 3600; 
    ll h = diff / 3600;
    ll min = (diff % 3600) / 60;
    ll sec = diff % 60;
    cout << setw(2) << setfill('0') << h << ":"
         << setw(2) << setfill('0') << min << ":"
         << setw(2) << setfill('0') << sec << endl;


}