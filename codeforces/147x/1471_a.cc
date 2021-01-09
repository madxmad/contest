#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

int main() { IO;
  int t;
  cin >> t;

  while (t--) {
    int n, x;
    cin >> n >> x;

    vector<long long> v(n);
    for (auto& a : v) {
      cin >> a;
    }

    long long mn = (accumulate(v.begin(), v.end(), 0LL) + x - 1) / x;
    auto lambda = [x](long long total, long long a) { return total + (a + x - 1) / x;};
    long long mx = accumulate(v.begin(), v.end(), 0LL, lambda);
    cout << mn << " " << mx << endl;
  }

  return 0;
}
