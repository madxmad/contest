#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

int main() { IO;
  int t;
  cin >> t;

  vector<int> v(1000000, 9);
  int d = 8;
  for (int i = 1; i < v.size(); ++i) {
    v[i] = d;
    d = (d + 1 + 10) % 10;
  }

  while (t--) {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) cout << v[i];
    cout << endl;
  }

  return 0;
}
