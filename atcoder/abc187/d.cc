#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

int main() { IO;
  int n;
  cin >> n;

  long long aoki = 0;
  vector<pair<long long, long long>> votes(n);

  for (int k = 0; k < n; ++k) {
    int a, b;
    cin >> a >> b;

    aoki += a;
    votes[k] = {a, b};
  }

  auto sorter = [](const auto& a, const auto& b) {
    return 2 * a.first + a.second > 2 * b.first + b.second;
  };

  sort(votes.begin(), votes.end(), sorter);

  int ans = 0;
  long long takahashi = 0;

  for (int k = 0; aoki >= takahashi; ++k) {
    ++ans;
    aoki -= votes[k].first;
    takahashi += votes[k].first + votes[k].second;
  }

  cout << ans << endl;

  return 0;
}
