    #include <bits/stdc++.h>

    using namespace std;
    typedef long long ll;

    //const ll MOD = 10000019;
    const ll MOD = 1009, MOD2 = 998244351;
    const ll p1 = 31, p2 = 101;
    const int maxN = 1e4 + 5;

    const int N = 10;
    vector<string> mat(10);
    vector<vector<ll>> has1(10, vector<ll> (maxN)), has2(10, vector<ll> (maxN));
    vector<ll> pow1(maxN), pow2(maxN);


    void init(){
        pow1[0] = pow2[0] = 1;
        for(int i = 1; i < maxN; i++) {pow1[i] = (pow1[i-1] * p1) % MOD; pow2[i] = (pow2[i-1] * p2) % MOD2;}
        for(int i = 0; i < N; i++) has1[i][0] = has2[i][0] = 0;
        
        for(int i = 0; i < N; i++){
            for(int j = 1; j <= mat[i].size(); j++){
                int c = (int) (mat[i][j - 1] - 'a' + 1);
                has1[i][j] = (has1[i][j - 1] + c * pow1[j - 1]) % MOD;
                has2[i][j] = (has2[i][j - 1] + c * pow2[j - 1]) % MOD2;
            }
        }
        
    }

    signed main(){
        int n; cin>>n;
        int res[n][n];
        for(int i = 0; i < n; i++) cin>>mat[i];
        init();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j == i) {res[i][j] = 0; continue;}
                int ans = 0;
                for(int len = min(mat[i].size(), mat[j].size()); len >= 1; len--){
                    if(((has1[i][mat[i].size()] - has1[i][mat[i].size() - len] + MOD) * pow1[len] % MOD) == ((has1[j][len] - has1[j][0] + MOD) * pow1[mat[i].size()] % MOD) && ((has2[i][mat[i].size()] - has2[i][mat[i].size() - len] + MOD2) * pow2[len] % MOD2) == ((has2[j][len] - has2[j][0] + MOD2) * pow2[mat[i].size()] % MOD2)) {ans = len; break;}
                }
                res[i][j] = ans;
            }
        }

        vector<int> vec(n);
        int suma = 0;
        for(int i = 0; i < n; i++) {vec[i] = i + 1; suma += mat[i].size();}
        /*for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) cout<<res[i][j]<<" ";
            cout<<endl;
        }*/
        int mx = 1e8;
        do {
            int ga = suma;
            for (int i = 0; i < n - 1; i++) {
                ga -= res[vec[i] - 1][vec[i + 1] - 1];
            }
            mx = min(mx, ga);
            
        } while (next_permutation(vec.begin(), vec.end()));
        cout<<mx;

        return 0;

    }