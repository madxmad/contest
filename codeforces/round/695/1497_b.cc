#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

int intimidation(const vector<int>& v, int index) {
  const int n = v.size();
  if (1 <= index && index <= n - 2) {
    int hill = (v[index - 1] < v[index]) && (v[index] > v[index + 1]);
    int valley = (v[index - 1] > v[index]) && (v[index] < v[index + 1]);
    return hill + valley;
  }

  return 0;
}

int main() { IO;
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto& x : v) cin >> x;

    vector<int> cnt(n, 0);
    for (int i = 1; i < n - 1; ++i) {
      cnt[i] = intimidation(v, i);
    }

    int mx = 0;
    for (int i = 1; i < n - 1; ++i) {
      const int old_value = v[i];
      int c = n;
      for (int j : {i - 1, i + 1}) {
        for (int k : {-1, 0, 1}) {
          v[i] = v[j] + k;
          int value = intimidation(v, i - 1) + intimidation(v, i) + intimidation(v, i + 1);
          c = min(c, value);
          // cout << v[i] << " = " << value << endl;
        }
      }
      v[i] = old_value;
      mx = max(mx, cnt[i - 1] + cnt[i] + cnt[i + 1] - c);
    }
    // cout << "mx: " << mx << endl;

    int ans = accumulate(cnt.begin(), cnt.end(), 0);
    ans -= mx;

    cout << ans << endl;
  }

  return 0;
}
