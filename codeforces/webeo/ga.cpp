#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long ll;
string s;
vector<string> ans;
int len;

bool ok(int *i){
    string c; char ant = 'a';
    for(int j = *i; j < len; j++){
        if(s[j] == 'a'){
            if(ant == '}'){
                ans.push_back(c);
                *i = j - 1;
                return false;
            }
            c += '1';
            ant = 'a';
        } else if(s[j] == '+'){
            if(ant == 'a' || ant == '}'){
                if(c.empty()){
                    *i = j;
                    return false;
                }
                c += '0';
                ant = '+';
            } else {
                ans.push_back(c);
                *i = j ;
                return false;
            }
        
        } else if(s[j] == '('){
            if(ant == 'a' || ant == '}'){
                if(c.empty()){
                    *i = j + 1;
                    if(ok(&(*i))){
                        j = *i;
                        c += '1';
                        ant = '}';
                    } else {
                        ans.push_back(c);
                        j = *i;
                        return false;
                    }
                } else{
                    ans.push_back(c);
                    *i = j - 1;
                    return false;
                }
            } else if(ant == '+'){
                *i = j + 1;
                if(ok(&(*i))) {
                    j = *i;
                    c += '1';
                    ant = '}';
                } else{
                    ans.push_back(c);
                    return false;
                }
            }
        } else {
            ans.push_back(c);
            *i = j;
            if(ant == 'a' || ant == '}'){
                if(!c.empty()){
                    return true;
                } else{
                    return false;
                }
            } else {
                return false;
            }
            
        }
    }
    ans.push_back(c);
    *i = len - 1;
    return false;

}

signed main(){
    fastio;
    cin>>s;
    len = s.size();
    for(int i = 0; i < len; i++){
        int a = s[i] - 'a';
        if(a >= 0 && a < 26) s[i] = 'a';
        if(s[i] == '*' || s[i] == '+' || s[i] == '-' || s[i] == '/') s[i] = '+';
    }

    string c; char ant = 'a';
    for(int i = 0; i < len; i++){
        if(s[i] == 'a'){
            if(ant == ')' || ant == '}'){
                ans.push_back(c);
                c.clear();
            }
            c += '1';
            ant = 'a';
        } else if(s[i] == '+'){
            if(ant == 'a' || ant == '}'){
                c += '0';
            } else {
                ans.push_back(c);
                c.clear();
            }
            ant = '+';
        } else if(s[i] == '('){
            if(ant != '+'){
                ans.push_back(c);
                c.clear();
                i++;
                if(ok(&i)){
                    c += '1';
                    ant = '}';
                } else ant = '+';
            } else if(ant == '+'){
                i++;
                if(ok(&i)) {c += '1'; ant = '}';}
                else{
                    ans.push_back(c);
                    c.clear();
                    ant = '+';
                }
            }
        } else {
            ant = '+';
            ans.push_back(c);
            c.clear();
        }
    }
    ans.push_back(c);

    ll sum = 0LL;
    for(int i = 0; i < ans.size(); i++){
        ll ad = 0LL;
        for(int j = 0; j < ans[i].size(); j++){
            if(ans[i][j] == '1') ad++;
        }
        sum += (ad * (ad + 1)) / 2;
    }
    cout<<sum;

    return 0;
}