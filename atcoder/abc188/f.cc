#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

unordered_map<long long, long long> dp;

long long solve(long long from, long long to) {
  if (from <= to) return to - from;

  if (!dp.count(from)) {
    if (from & 1) {
      dp[from] = 2 + min(solve(from / 2, to), solve(from / 2 + 1, to));
    } else {
      dp[from] = 1 + solve(from / 2, to);
    }
    dp[from] = min(dp[from], from - to);
  }

  return dp[from];
}

int main() { IO;
  long long from, to;
  cin >> from >> to;

  long long ans = solve(to, from);
  cout << ans << endl;

  return 0;
}
