#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
vector <int> prime;
bool is_composite[MAXN];

void sieve_normal (int n) {
	fill (is_composite, is_composite + n, false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.push_back (i);
		for (int j = 2; i * j < n; ++j)
			is_composite[i * j] = true;
	}
}

void sieve_best (int n) {
	fill (is_composite, is_composite + n, false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) {
        prime.push_back (i);
		for (int j = 2; i * j < n; ++j)
			is_composite[i * j] = true;
        }
	}
}

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

int main(){
	sieve_linear(10);
    for(auto& elem: prime) cout<<elem<<" ";
    
}
