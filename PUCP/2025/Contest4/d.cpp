#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    vector<string> vec;
    while(getline(cin, vec.emplace_back())) {
    }
    if(vec.back().empty()) {
        vec.pop_back();
    }

    int i = 0, j = 0;
    int i_min = i, i_max = i, j_min = j, j_max = j;
    for(int k = 0; k < vec.size(); k++) {
        if(vec[k][0] == 'u') {
            j--;
            j_min = min(j, j_min);
        } else if(vec[k][0] == 'd') {
            j++;
            j_max = max(j, j_max);
        } else if(vec[k][0] == 'l') {
            i--;
            i_min = min(i, i_min);
        } else if(vec[k][0] == 'r') {
            i++;
            i_max = max(i, i_max);
        } 
    }

    int width = i_max - i_min + 3;
    int height = j_max - j_min + 3;
    //cout << width << " " << height << endl;
    char mat[height][width];
    for(int k = 0; k < height; k++) {
        for(int l = 0; l < width; l++) {
            mat[k][l] = ' ';
        }
    }

    for(int k = 0; k < height; k++) {
        mat[k][0] = mat[k][width - 1] = '#';
    }

    for(int k = 0; k < width; k++) {
        mat[0][k] = mat[height - 1][k] = '#';
    }

    i =  - i_min + 1;
    j =  - j_min + 1;
    int a_i = i, a_j = j;
    for(int k = 0; k < vec.size(); k++) {
        if(vec[k][0] == 'u') {
            j--;
        } else if(vec[k][0] == 'd') {
            j++;
        } else if(vec[k][0] == 'l') {
            i--;    
        } else if(vec[k][0] == 'r') {
            i++;
        } 
        mat[j][i] = '*';
    }
    mat[j][i] = 'E';
    mat[a_j][a_i] = 'S';

    for(int k = 0; k < height; k++) {
        for(int l = 0; l < width; l++) {
            cout << mat[k][l];
        }
        cout << endl;
    }

}