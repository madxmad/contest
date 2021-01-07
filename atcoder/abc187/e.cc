#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

struct node {
  long long value;
  map<int, long long> neighbors;
};

long long up(vector<node> &G, int current, int parent) {
  long long total = G[current].neighbors[parent];
  for (const auto& [next, cost] : G[current].neighbors) {
    if (next == parent) {
      continue;
    }
    total += up(G, next, current);
  }

  return total;
}

void down(vector<node> &G, int current, int parent) {
  G[current].value = G[parent].value + G[parent].neighbors[current] - G[current].neighbors[parent];
  for (const auto& [next, _] : G[current].neighbors) {
    if (next == parent) {
      continue;
    }
    down(G, next, current);
  }
}

int main() { IO;
  int n;
  cin >> n;

  vector<node> G(n + 1);
  vector<vector<int>> edges(n + 1);

  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    G[a].neighbors[b] = 0;
    G[b].neighbors[a] = 0;
    edges[i] = {a, b};
  }

  int q;
  cin >> q;

  for (int k = 1; k <= q; ++k) {
    int t, e, x;
    cin >> t >> e >> x;
    t--;

    int a = edges[e][!t];
    int b = edges[e][t];
    G[a].neighbors[b] += x;
  }

  long long total = up(G, 1, 0);
  G[0].value = total;
  down(G, 1, 0);

  for (int i = 1; i <= n; ++i) {
    cout << G[i].value << endl;
  }

  return 0;
}
