#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

const double eps = 1e-6;

int main() { IO;
  int n;
  double x;
  cin >> n >> x;

  vector<int> v(n);
  vector<double> p(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i] >> p[i];
  }

  double total = 0;
  for (int i = 0; i < n; ++i) {
    total += v[i] * p[i] / 100.;
    if (total > x + eps) {
      cout << i + 1 << endl;
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}
