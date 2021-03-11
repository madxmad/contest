#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

int main() { IO;
  int n;
  cin >> n;

  vector<int> v(n);
  for (auto &x : v) {
    string s;
    cin >> s;
    x = (s == "AND");
  }

  vector<vector<long long>> dp(n + 1, vector<long long>(2, 1));
  for (int i = 1; i <= n; ++i) {
    for (int expected = 0; expected <= 1; ++expected) {
      if (expected == v[i - 1]) {
        dp[i][expected] = dp[i - 1][expected];
      } else {
        dp[i][expected] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][!v[i - 1]];
      }
    }
  }

  cout << dp[n][1] << endl;

  return 0;
}
