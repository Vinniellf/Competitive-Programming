#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const string no = "none";
const string am = "ambiguous";
const string ENDL = "\n";

int n; 
vector<string> word(10000);

void buscar(string a, string b){
    string ans1, ans2;
    for(int k = 0; k < n; k++){
        bool ok = true;
        for(int l = 0; l < a.size(); l++){
            if(word[k][l] != a[l]) {ok = false; break;}
        }
        if(ok) {ans1 = word[k]; break;}
    }

    for(int k = 0; k < n; k++){
        bool ok = true;
        for(int l = 0; l < b.size(); l++){
            if(word[k][word[k].size() - 1 - l] != b[l]) {ok = false; break;}
        }
        if(ok) {ans2 = word[k]; break;}
    }
    reverse(b.begin(), b.end());
    if(ans1 == a + b) cout<<no;
    else cout<<ans1<<" "<<ans2;
    cout<<ENDL;

}

int main(){
    //freopen("input.txt", "r", stdin);
    int m; cin>>n>>m;
    map<string, int> dicc, dicc_reves;
    string palabra, reves, ans;
    // Creamos nuestro diccionario;
    for(int i = 0; i < n; i++) {
        cin>>word[i];
        palabra = ""; reves = "";
        for(int j = 0; j < word[i].size(); j++){
            palabra += word[i][j]; reves += word[i][word[i].size() - 1 - j];
            dicc_reves[reves]++;
            dicc[palabra]++;
        }
    }
    for(int i = 0; i < m; i++) {
        cin>>ans;
        vector<string> mat(ans.size()), rev(ans.size());
        palabra = ""; reves = "";
        bool ok; int res; bool ambi;
        for(int j = 0; j < ans.size(); j++) {
            palabra += ans[j]; reves += ans[ans.size() - 1 - j];
            mat[j] = palabra; rev[j] = reves;
        }
        if(ans.size() < 5) cout<<no<<ENDL;
        else if(ans.size() == 5){
            if(dicc[mat[2]] == 0 || dicc_reves[rev[2]] == 0) cout<<no<<ENDL;
            else if(dicc[mat[2]] == 1 && dicc_reves[rev[2]] == 1) buscar(mat[2], rev[2]);
            else cout<<am<<ENDL;
        } else {
            ok = false;
            ambi = false;
            res = -1;
            for(int j = 2; j < ans.size() - 3; j++) {
                if(dicc[mat[j]] == 1) {
                    if(dicc_reves[rev[ans.size() - 2 - j]] == 1) {ok = true; res = j;}
                    else if (dicc_reves[rev[ans.size() - 2 - j]] > 1) {ambi = true; break;}
                } else if(dicc[mat[j]] > 1){
                    if (dicc_reves[rev[ans.size() - 2 - j]] > 0) {ambi = true; break;}
                }
            }
            if(ambi) {cout<<am<<ENDL; continue;}
            if(ok) buscar(mat[res], rev[ans.size() - 2 - res]);
            else cout<<no<<ENDL;
        }

    }
    


    
}