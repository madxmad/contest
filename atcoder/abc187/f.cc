#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

vector<int> dp(1 << 18);

bool is_clique(const vector<int>& G, int clique) {
  for (int i = 0; i < G.size(); ++i) {
    if (clique & (1 << i)) {
      if ((G[i] & clique) != clique) {
        return false;
      }
    }
  }

  return true;
}

int main() { IO;
  int n, m;
  cin >> n >> m;

  vector<int> G(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a] |= 1 << b;
    G[b] |= 1 << a;
  }

  for (int i = 0; i < n; ++i) {
    G[i] |= 1 << i;
  }

  dp[0] = 0;
  for (int mask = 1; mask < (1 << n); ++mask) {
    if (is_clique(G, mask)) {
      dp[mask] = 1;
    } else {
      dp[mask] = n;
    }
  }

  for (int mask = 1; mask < (1 << n); ++mask) {
    for (int clique = mask; clique; clique=(clique - 1) & mask) {
      dp[mask] = min(dp[mask], dp[clique] + dp[mask ^ clique]);
    }
  }

  cout << dp[(1 << n) - 1] << endl;

  return 0;
}
