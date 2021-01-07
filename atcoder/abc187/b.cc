#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

int main() { IO;
  int n;
  cin >> n;

  vector<int> x(n), y(n);
  for (int k = 0; k < n; ++k) {
    cin >> x[k] >> y[k];
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      const double dx = abs(x[i] - x[j]);
      const double dy = abs(y[i] - y[j]);
      ans += dx >= dy;
    }
  }

  cout << ans << endl;

  return 0;
}
