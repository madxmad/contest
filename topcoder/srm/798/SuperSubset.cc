#include<bits/stdc++.h>
using namespace std;

class SuperSubset {
  const int mod = 1000 * 1000 * 1000 + 7;
  vector<int> values;
  vector<vector<long long>> memo;

  int dp(int sum, int i) {
    if (sum == 0 && i == -1) return 1;
    if (sum < 0 || i == -1) return 0;
    if (memo[sum][i] == -1) {
      memo[sum][i] = 2LL * dp(sum, i - 1) + dp(sum - values[i], i - 1);
      memo[sum][i] %= mod;
    }
    return memo[sum][i];
  }

  void init(int sum, const vector<int>& v) {
    values = v;
    reverse(values.begin(), values.end());
    memo.resize(sum + 1);
    for (auto& x : memo) x.resize(v.size(), -1);
  }

 public:
  int solve(vector <int> v, int sum) {
    init(sum, v);
    return dp(sum, v.size() - 1);
  }
};
