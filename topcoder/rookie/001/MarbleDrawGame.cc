#include<bits/stdc++.h>
using namespace std;

class MarbleDrawGame {
public:
  map<vector<int>, double> dp;

  long long C (int n, int r) {
    if (r > n) return 0;

    long long ans = 1;
    const int limit = max(r, n - r);
    for (int i = max(r, n - r) + 1; i <= n; ++i) ans *= i;
    for (int i = 1; i <= min(r, n - r); ++i) ans /= i;
    return ans;
  }
  
  double winningChance(vector <int> marbles) {
    const int sum = accumulate(marbles.begin(), marbles.end(), 0);
    const long long total = C(sum, 9);

    double ans = 0;
    for (int c : marbles) {
      for (int x = 5; x <= 9; ++x) {
        ans += 1. * C(c, x) * C(sum - c, 9 - x) / total;
      }
    }

    return ans;
  }
};
