    #include<bits/stdc++.h>
    using namespace std;
    #define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
    #define rep(i,n) for (int i = 0; i < n; ++i)
    #define all(v) (v).begin(),(v).end()

    typedef unsigned long long ll;
    const ll MOD = 998244353;
    const ll MOD2 = 1e9 + 7;

    const ll p1 = 10007, p2 = 10009;
    //const ll MOD = 1e9 + 7; 

    void solve(){
        int n, k;
        cin>>n>>k;
        
        vector<ll> h1(n + 1), h2(n + 1), vec(n + 1);
        vector<ll> pow1(n + 1), pow2(n + 1);

        rep(i, n) cin>>vec[i];
        ///
        pow1[0] = pow2[0] = 1;
        for(int i = 1; i <= n; i++) {pow1[i] = (pow1[i - 1] * p1) % MOD; pow2[i] = (pow2[i - 1] * p2) % MOD2;}
        
        ll has1 = 0LL, has2 = 0LL;
        for(int i = 1; i <= k; i++){
            has1 = (has1 + pow1[i]) % MOD;
            has2 = (has2 + pow2[i]) % MOD2;
        }

        h1[0] = h2[0] = 0;
        vector<int> matMin(n + 1, 0), matCount(n + 1, 0); matMin[0] = k;
        int c = 0;
        for(int i = 1; i <= n; i++){
            int num = vec[i - 1];
            h1[i] = (h1[i - 1] + pow1[vec[i - 1]]) % MOD;
            h2[i] = (h2[i - 1] + pow2[vec[i - 1]]) % MOD2;

            matCount[num]++;
            matMin[matCount[num]]++;
            matMin[matCount[num] - 1]--;

            if(matMin[c] == 0){
                c++;
                h1[i] = (h1[i] - has1 + MOD) % MOD;
                h2[i] = (h2[i] - has2 + MOD2) % MOD2;
            }
        }

        ///
        vector<pair<ll, int>> ans(n + 1);
        for(int i = 0; i <= n; i++){
            ans[i] = {h1[i] * 1000000000 + h2[i], i};
        }
        sort(all(ans));
        int mx = 0;
        ll ansVal = ans[0].first; int ansMin = ans[0].second, ansMax = ans[0].second;
        for(int i = 1; i <= n; i++){
            if(ans[i].first != ansVal){
                mx = max(mx, ansMax - ansMin);
                ansMin = ansMax = ans[i].second;
                ansVal = ans[i].first;
            } else {
                ansMax = ans[i].second;
            }
        }
        mx = max(mx, ansMax - ansMin);
        cout<<mx<<endl;
        //for(int i = 0; i <= n; i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
        
    }


    int main(){
    //freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
        fastio;
        int t=1;
        //cin>>t;
        while(t--){
            solve();
        }

        return 0;
    }