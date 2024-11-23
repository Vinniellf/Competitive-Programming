#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e6 + 5;


void solve(){
    int n; cin>>n;
    vector<int> vec(n + 1);
    int count = 0;
    int val = 1;
    for(int i = 1; i <= n; i++){
        count++;
        if(i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000){
            if(count != 1) val++;
            count = 1;
            vec[i] = val;
            continue;
        }
        if(count == 500){
            count = 0;
            vec[i] = val;
            val++;
            continue;
        }
        vec[i] = val;

    }

    cout<<vec[n];
    


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    while(t--){solve();}
    return 0;
}