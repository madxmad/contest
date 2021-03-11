#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

int main() { IO;
  int n;
  cin >> n;

  vector<int> v(n);
  for (auto &x : v) cin >> x;

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int mn = v[i];
    for (int j = i; j < n; ++j) {
      mn = min(mn, v[j]);
      ans = max(ans, mn * (j - i + 1));
    }
  }
  cout << ans << endl;

  return 0;
}
