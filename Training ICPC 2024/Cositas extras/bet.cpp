#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define REP(i,k,n) for (int i = k; i <n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()

const int N = 240;
const double factor = 300;
double lim = 1000;
vector<int> h(N), v(N);
vector<vector<double>> bet(3, vector<double>(N));
char r[N];

double ganancia_pos(){
    double suma = 0;
    int total_neto = 0;

    for(int i = 0; i < N; i++){
        if(bet[0][i] < bet[1][i] and bet[0][i] < bet[2][i]) {
            if(bet[0][i] >= lim) continue;
            total_neto++;
            if(r[i] == 'H') {suma += bet[0][i]; continue;}
            
        }
        if(bet[1][i] < bet[0][i] and bet[1][i] < bet[2][i]) {
            if(bet[1][i] >= lim) continue;
            total_neto++;
            if(r[i] == 'D') {suma += bet[1][i]; continue;}
        }
        if(bet[2][i] < bet[1][i] and bet[2][i] < bet[0][i]) {
            if(bet[2][i] >= lim) continue;
            total_neto++;
            if(r[i] == 'A') {suma += bet[2][i]; continue;}
        }
        suma -= 1;
    }
    return ( suma - total_neto )* factor;
}

double ganancia_neg(){
    double suma = 0;
    int total_neto = 0;

    for(int i = 0; i < N; i++){
        if(bet[0][i] > bet[1][i] and bet[0][i] > bet[2][i]) {
            if(bet[0][i] >= lim) continue;
            total_neto++;
            if(r[i] == 'H') {suma += bet[0][i]; continue;}
            
        }
        if(bet[1][i] > bet[0][i] and bet[1][i] > bet[2][i]) {
            if(bet[1][i] >= lim) continue;
            total_neto++;
            if(r[i] == 'D') {suma += bet[1][i]; continue;}
        }
        if(bet[2][i] > bet[1][i] and bet[2][i] > bet[0][i]) {
            if(bet[2][i] >= lim) continue;
            total_neto++;
            if(r[i] == 'A') {suma += bet[2][i]; continue;}
        }
        suma -= 1;
    }
    cout<<"total ganancia neg: "<<total_neto<<endl;
    return ( suma - total_neto )* factor;
}

int rate(){
    int ans = 0;
    int total_neto = 0;

    for(int i = 0; i < N; i++){
        if(bet[0][i] < bet[1][i] and bet[0][i] < bet[2][i]) {
            if(bet[0][i] >= lim) continue;
            total_neto++;
            if(r[i] == 'H') ans++;
        }
        if(bet[1][i] < bet[0][i] and bet[1][i] < bet[2][i]) {
            if(bet[1][i] >= lim) continue;
            total_neto++;
            if(r[i] == 'D') ans++;
        }
        if(bet[2][i] < bet[1][i] and bet[2][i] < bet[0][i]) {
            if(bet[2][i] >= lim) continue;
            total_neto++;
            if(r[i] == 'A') ans++;
        }

    }
    if(total_neto == 0) return 0.0;
    return ((ans * 1.0)/total_neto) * 100;

}

int rate_neg(){
    int ans = 0;
    int total_neto = 0;

    for(int i = 0; i < N; i++){
        if(bet[0][i] > bet[1][i] and bet[0][i] > bet[2][i]) {
            if(bet[0][i] >= lim) continue;
            total_neto++;
            if(r[i] == 'H') ans++;
        }
        if(bet[1][i] > bet[0][i] and bet[1][i] > bet[2][i]) {
            if(bet[1][i] >= lim) continue;
            total_neto++;
            if(r[i] == 'D') ans++;
        }
        if(bet[2][i] > bet[1][i] and bet[2][i] > bet[0][i]) {
            if(bet[2][i] >= lim) continue;
            total_neto++;
            if(r[i] == 'A') ans++;
        }

    }
    cout<<"total rate neg: "<<total_neto<<endl;
    return ((ans * 1.0)/total_neto) * 100;

}

void zeroTzero(){
    int count = 0;
    for(int i = 0; i < N; i++){
        if(h[i] == v[i] && h[i] == 0) count++;
    }
    cout<<count;

}

int main(){
    freopen("input2.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    fastio;
    
    for(int i = 0; i < N; i++){
        cin>>h[i]>>v[i]>>r[i]>>bet[0][i]>>bet[1][i]>>bet[2][i];
    }

    zeroTzero();
    return 0;
    int count = 0;
    /*for(int i = 101; i <= 400; i++){
        double pene2 = i/100.0;
        lim = pene2;
        double pene = ganancia_pos();
        if(pene < 0.0) continue;
        count++;
        cout<<"-----\n";
        cout<<"Ganancia "<<count<<endl;
        cout<<"Limite : "<<pene2<<endl;
        cout<<"Porcentaje: "<<rate()<<endl;
        cout<<"Neto: "<<pene<<endl;
    }*/
    cout<<"Porcentaje: "<<rate()<<endl;
    cout<<"Neto: "<<ganancia_pos()<<endl;
    cout<<"-----\n";
    lim = 300;
    cout<<rate_neg()<<endl;
    cout<<ganancia_neg()<<endl;

    return 0;
}
