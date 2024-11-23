#include <bits/stdc++.h>
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> p(n);
    auto query = [&] (int a, int b) {
      cout << "? " << a << ' ' << b << endl;
      int res;
      cin >> res;
      return res;
    };
    int l = n-2;
    for (int i = n-1; i >= 0; i--) {
      while (l && query(i, l)) l--;
      p[i] = l;
      if (l) l--;
    }
    cout << "!";
    for (int i = 1; i < n; i++) cout << ' ' << p[i];
    cout << endl;
  }
}