#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

int main() { IO;
  int k;
  cin >> k;

  const int n = 1 << k;
  vector<int> v(n);
  for (auto& x : v) cin >> x;

  auto left = max_element(v.begin(), v.begin() + n / 2);
  auto right = max_element(v.begin() + n / 2, v.end());

  int ans;
  if (*left < *right) {
    ans = distance(v.begin(), left);
  } else {
    ans = distance(v.begin(), right);
  }

  cout << ans + 1 << endl;

  return 0;
}
