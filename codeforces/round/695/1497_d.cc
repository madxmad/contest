#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

const int mod = 1000 * 1000 * 1000 + 7;

int main() { IO;
  int n, k, q;
  cin >> n >> k >> q;

  vector<long long> v(n + 1);
  for (int i = 1; i <= n; ++i) cin >> v[i];

  vector<vector<long long>> dp(k + 1, vector<long long>(n + 2, 0));
  for (int col = 1; col <= n; ++col) dp[0][col] = 1;

  for (int row = 1; row <= k; ++row) {
    for (int col = 1; col <= n; ++col) {
      dp[row][col] += dp[row - 1][col - 1] + dp[row - 1][col + 1];
      dp[row][col] %= mod;
    }
  }

  /*for (int row = 1; row <= k; ++row) {
    for (int col = 1; col <= n; ++col) cout << dp[row][col] << " ";
    cout << endl;
    }*/

  vector<long long> cnt(n + 1, 0);
  for (int number = 1; number <= n; ++number) {
    for (int pos = 0; pos <= k; ++pos) {
      cnt[number] += dp[pos][number] * dp[k - pos][number];
      cnt[number] %= mod;
    }
  }

  // for (int number = 1; number <= n; ++number) cout << cnt[number] << " "; cout << endl;

  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += v[i] * cnt[i];
    ans %= mod;
  }

  while (q--) {
    long long index, value;
    cin >> index >> value;
    ans += cnt[index] * (value - v[index]);
    v[index] = value;
    ans %= mod;
    ans += mod;
    ans %= mod;
    cout << ans << endl;
  }

  return 0;
}
