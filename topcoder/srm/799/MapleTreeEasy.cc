#include<bits/stdc++.h>
using namespace std;

class disjointset {
 public:
  int n;
  vector<int> parent, cnt;

  disjointset(int _n) {
    n = _n;
    parent.resize(n);
    cnt.resize(n);
    makeset();
  }

  void makeset() {
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
      cnt[i] = 1;
    }
  }

  int findset(int x) {
    if (parent[x] != x) parent[x] = findset(parent[x]);
    return parent[x];
  }

  int count(int x) {
    return cnt[findset(x)];
  }

  void join(int x, int y) {
    int x_set = findset(x);
    int y_set = findset(y);

    if (x_set != y_set) {
      int total = cnt[x_set] + cnt[y_set];
      cnt[x_set] = total;
      cnt[y_set] = total;
    }

    parent[x_set] = y_set;
  }
};

class MapleTreeEasy {
 public:
  long long count(vector <int> p) {
    const int n = 1 + p.size();

    vector<vector<int>> G(n);
    G.resize(n);

    for (int i = 0; i < p.size(); ++i) {
      int j = p[i];
      G[i + 1].push_back(j);
      G[j].push_back(i + 1);
    }

    set<int> bridges;
    for (int i = 0; i < n; ++i) {
      if (G[i].size() >= 3) {
        bridges.insert(i);
      }
    }

    disjointset ds(n);
    for (int i = 0; i < n; ++i) {
      for (auto j : G[i]) {
        if (!bridges.count(i) && !bridges.count(j)) {
          ds.join(i, j);
        }
      }
    }

    vector<int> ids;
    for (int i = 0; i < n; ++i) {
      ids.push_back(ds.findset(i));
    }
    sort(ids.begin(), ids.end());
    ids.erase(unique(ids.begin(), ids.end()), ids.end());

    vector<vector<int>> dist(n, vector<int>(n, 1 << 20));
    for (int from = 0; from < n; ++from) {
      dist[from][from] = 0;
      for (auto to : G[from]) {
        dist[from][to] = 1;
      }
    }

    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (dist[i][j] > dist[i][k] + dist[k][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
          }
        }
      }
    }

    for (int from : ids) {
      for (int to : ids) {
        if (from == to) continue;
        for (int i = 0; i < n; ++i) {
          if (ds.findset(i) != from) continue;
          for (int j = 0; j < n; ++j) {
            if (ds.findset(j) != to) continue;
            dist[from][to] = min(dist[from][to], dist[i][j]);
          }
        }
      }
    }

    long long ans = 0;
    for (int i = 0; i < ids.size(); ++i) {
      int from = ids[i];
      ans += (1LL << ds.count(from)) - 1;
      for (int j = i + 1; j < ids.size(); ++j) {
        int to = ids[j];
        long long a = (1LL << ds.count(from)) - 1;
        long long b = (1LL << ds.count(to)) - 1;
        long long c = 1LL << (dist[from][to] - 1);
        ans += a * b * c;
      }
    }

    return ans;
  }
};
