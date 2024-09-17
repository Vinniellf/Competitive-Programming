#include <bits/stdc++.h>
using namespace std;

int main(){
    int s = 5;
    int b = 0;
    do{
        cout<<"sub "<<b<<"\n";
    } while(b = (b - s)&s);
    return 0;
}