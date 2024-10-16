#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1000;
vector <int> prime;
bool is_composite[MAXN];

void sieve_linear (int n) {
	fill (is_composite, is_composite + n, false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.push_back (i);
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}


void solve(){
    int x; cin>>x;
    int ans = 1;
    for(int i = 0; i < prime.size(); i++){
        if(x == 1) break;
        int count = 0;
        while(x % prime[i] == 0){
            count++;
            x /= prime[i];
        }
        ans *= (count + 1);
    }
    cout<<(x > 1? ans*2 : ans)<<"\n";
    
}

signed main(){
    int t; cin>>t;
    sieve_linear(1000);
    while(t--){
        solve();
    }
}