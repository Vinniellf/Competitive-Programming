#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()

void solve(){
    int n; cin>>n;
    double per; cin>>per;
    vector<pair<double, double>> vec(n);
    rep(i, n) cin>>vec[i].second>>vec[i].first;
    rep(i, n) vec[i].first -= per;
    vector<pair<double, double>> menor, mayor;

    double ans = 0.0;

    rep(i, n){
        if(vec[i].first < 0) menor.push_back(vec[i]);
        else if(vec[i].first > 0) mayor.push_back(vec[i]);
        else ans += vec[i].second;
    }
    sort(all(menor)); sort(all(mayor)); reverse(all(menor));
    int me = menor.size();
    int ma = mayor.size();
    
    
   int i = 0, j = 0;
   while (i != me && j != ma) {
        double u_me, u_ma;
        u_me = menor[i].first * menor[i].second * (-1.0);
        u_ma = mayor[j].first * mayor[j].second;
        if(u_me > u_ma){
            ans += mayor[j].second + u_ma/(menor[i].first * (-1.0));
            menor[i].second -= u_ma/(menor[i].first * (-1.0));
            j++;
        } else {
            ans += menor[i].second + u_me/mayor[j].first;
            mayor[j].second -= u_me/mayor[j].first;
            i++;
        }   
   }
   cout<<ans<<endl;
    
}

signed main(){
    fastio;
    solve();

    return 0;
}