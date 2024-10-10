#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
int res;

void sol(int rana, int pos){
    if(pos == rana - res){
        if(vec[pos + 1] == -1){
            if(rana + 1== vec.size()) return;
            for(int j = 1; j <= vec.size()/2; j++){
                vec[pos + j] = vec[pos + j + 1];
                vec[pos + j + 1] = -1;
                for(int k = 0; k < vec.size(); k++) cout<<vec[k]<<" "; 
                cout<<"\n";
            }
        }
        return;
    }
    if(vec[pos - 1] == -1) {vec[pos - 1] = rana; vec[pos] = -1; pos = pos - 1;}
    else {vec[pos + 1] = vec[pos - 1]; vec[pos - 1] = -1;} 
    for(int i = 0; i < vec.size(); i++) cout<<vec[i]<<" "; 
    cout<<"\n";
    sol(rana, pos);
}

int main(){
    int n; cin>>n;
    int si = 2*n + 1;
    vec.resize(si);
    int val = 1;
    for(int i = 0; i < si; i++){
        vec[i] = val;
        if(i == (si)/2) {val--; vec[i] = -1;}
        val++;
    }
    res = si/2 + 1;
    for(int i = 0; i < vec.size(); i++) cout<<vec[i]<<" "; 
    cout<<"\n";
    for(int i = si/2 + 1; i < si; i++) sol(i, i);
    
    return 0;
}