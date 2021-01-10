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

    vector<long long> cnt(n, 1);
    long long ans = accumulate(v.begin(), v.end(), 0LL);

    bool running = true;
    while (running) {
      for (int i = 0; i < n; ++i) {
        long long value = v[i];
        if (value % x) {
          running = false;
          break;
        }

        v[i] = value / x;
        cnt[i] = cnt[i] * x;
        ans += v[i] * cnt[i];
        // cout << "append " << v[i] << " " << cnt[i] << " times\n";
      }
    }
    cout << ans << endl;
  }

  return 0;
}
