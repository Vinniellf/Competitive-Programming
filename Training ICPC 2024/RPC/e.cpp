#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()

const int INF = 1e9;

void solve(){
    vector<pair<int, int>> vec(4);
    for(int i = 0; i < 4; i++) cin>>vec[i].second;
    for(int i = 0; i < 4; i++) cin>>vec[i].first;
    int h, w; cin>>h>>w;
    int ans = 0;
    int count_k = 0;
    for(int i = 0; i < h; i++) {
        string s; cin>>s;
        for(int j = 0; j < w; j++) {
            if(s[j] == 'C'){
                vec[0].first--; ans += vec[0].second;
            } else if (s[j] == 'M'){
                vec[1].first--; ans += vec[1].second;
            } else if (s[j] == 'Y'){
                vec[2].first--; ans += vec[2].second;
            } else if (s[j] == 'R'){
                vec[1].first--; vec[2].first--; ans += vec[1].second + vec[2].second;
            } else if (s[j] == 'G'){
                vec[2].first--; vec[0].first--; ans += vec[2].second + vec[0].second;
            } else if (s[j] == 'B'){
                vec[1].first--; vec[0].first--; ans += vec[1].second + vec[0].second;
            } else if (s[j] == 'K'){
                count_k++;
            }
        }
    }

    int val_com = 0; rep(i, 3) val_com += vec[i].second;
    int mn = INF; rep(i, 3) mn = min(mn, vec[i].first);

    if(val_com < vec[3].second){
        if(count_k > mn) ans += val_com * mn + (count_k - mn) * vec[3].second;
        else ans += val_com * count_k;
    } else {
        if(count_k > vec[3].first) ans += val_com * (count_k - vec[3].first) + vec[3].first * vec[3].second;
        else ans += vec[3].second * count_k;
    }

    cout<<ans<<endl;


    
}

signed main(){
    fastio;
    solve();

    return 0;
}