
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {
    int srand(0);
    int correct = 0;

    for(int i = 0; i < 150; i++) {
        int y = (rand()%1000 + 1);
        cout << "push " << y << endl;
        fflush(stdout);
        cout << "pop" << endl;
        fflush(stdout);
        int x;
        cin >> x;
        if (x == y) correct++;
    }
    if(correct == 150) cout << "pila" << endl;
    else cout << "cola" << endl;

    return 0;
}