#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

struct node {
  int value, parent;
  int in, out;
  bool skip;
  vector<int> children;
};

int dfs(int cur, int parent, int time, map<int, vector<int>>& times_by_value, vector<node>& G) {
  node& current = G[cur];
  current.parent = parent;

  times_by_value[current.value].push_back(time);
  current.in = time;
  ++time;

  for (int next : current.children) {
    if (next == parent) continue;
    time = dfs(next, cur, time, times_by_value, G);
  }

  current.out = time;
  ++time;

  return time;
}

bool value_in_range(int value, int begin, int end, const vector<int>& times) {
  auto it = lower_bound(times.begin(), times.end(), begin);
  // it = lower_bound(it, times.end(), value);
  return (it != times.end()) && (*it < end);
}

int solve(vector<node>& G, map<int, vector<int>>& times_by_value) {
  const int n = G.size() - 1;
  const int max_time = n * 2;
  vector<int> skip(max_time + 1);

  for (int cur = 1; cur <= n; ++cur) {
    node& current = G[cur];
    current.skip = false;
    if (times_by_value[current.value].size() == 1) continue;

    int cnt = 0;
    for (int next : current.children) {
      const node& child = G[next];
      bool has_value = false;

      if (next == current.parent) {
        has_value = value_in_range(current.value, 1, current.in, times_by_value[current.value])
          || value_in_range(current.value, current.out + 1, max_time, times_by_value[current.value]);
      } else {
        has_value = value_in_range(current.value, child.in, child.out, times_by_value[current.value]);
      }
      cnt += has_value;

      current.skip = true;
      if (has_value) {
        if (next == current.parent) {
          skip[current.in] += 1;
          skip[current.out] += -1;
        } else {
          skip[1] += 1;
          skip[child.in] += -1;
          skip[child.out + 1] += 1;
          skip[max_time] += -1;
        }
      }
    }

    if (cnt > 1) return 0;
  }

  for (int i = 1; i <= max_time; ++i) skip[i] += skip[i - 1];

  int ans = 0;
  for (int cur = 1; cur <= n; ++cur) {
    const node& current = G[cur];
    ans += !skip[current.in]  && !current.skip;
  }

  return ans;
}

int main() { IO;
  int n;
  cin >> n;

  vector<node> G(n + 1);
  for (int i = 1; i <= n; ++i) cin >> G[i].value;

  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    G[a].children.push_back(b);
    G[b].children.push_back(a);
  }

  map<int, vector<int>> times_by_value;
  dfs(1, 1, 1, times_by_value, G);
  cout << solve(G, times_by_value) << endl;

  return 0;
}
