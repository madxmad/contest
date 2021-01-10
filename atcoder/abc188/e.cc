#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

int main() { IO;
  long long n, m;
  cin >> n >> m;

  vector<long long> sell(n);
  for (auto& x : sell) cin >> x;

  vector<pair<long long, long long>> roads(m);
  for (auto& [from, to] : roads) {
    cin >> from >> to;
    from--;
    to--;
  }
  sort(roads.begin(), roads.end());

  vector<long long> buy(n, 1 << 30);
  for (auto& [from, to] : roads) {
    buy[to] = min({buy[to], buy[from], sell[from]});
  }
  // for (auto cost : buy) cout << cost << " "; cout << endl;

  long long ans = -(1LL << 40);
  for (long long i = 1; i < n; ++i) {
    long long profit = sell[i] - buy[i];
    ans = max(ans, profit);
  }
  cout << ans << endl;

  return 0;
}
