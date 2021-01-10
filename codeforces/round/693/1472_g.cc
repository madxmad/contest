#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

struct node {
  int depth = - 1, depth_reached = -1;
  vector<int> children, parents;
};

struct state {
  int node_id, depth;
  bool operator < (const state& other) const {
    return depth > other.depth;
  }
};

void calculate_depth(vector<node>& G, int root) {
  queue<int> Q;
  Q.push(root);
  G[root].depth = 0;

  while (!Q.empty()) {
    const int from = Q.front();
    Q.pop();
    const int depth = G[from].depth;
    for (const int to : G[from].children) {
      if (G[to].depth == -1 || G[to].depth > depth + 1) {
        G[to].depth = depth + 1;
        Q.push(to);
      }
    }
  }
}

void update_depth(vector<node>& G) {
  const int n = G.size() - 1;

  for (int i = 1; i <= n; ++i) {
    G[i].depth_reached = G[i].depth;
  }

  priority_queue<state> PQ;
  for (int from = 1; from <= n; ++from) {
    for (const int to : G[from].children) {
      if (G[from].depth > G[to].depth) {
        // cout << "adding edge from " << from << " to " << to << endl;
        PQ.push({from, G[to].depth});
      }
    }
  }

  queue<int> Q;
  while (!PQ.empty()) {
    const state st = PQ.top();
    PQ.pop();
    node& target = G[st.node_id];
    const int depth = st.depth;
    // cout << "checking node_id: " << st.node_id << ", depth: " << st.depth << endl;
    if (target.depth_reached > depth) {
      target.depth_reached = depth;
      Q.push(st.node_id);
      while (!Q.empty()) {
        const node& to = G[Q.front()];
        Q.pop();
        for (const int parent : to.parents) {
          node& from = G[parent];
          // cout << "  " << parent << ": depth " << from.depth << endl;
          if (to.depth > from.depth && from.depth_reached > depth) {
            from.depth_reached = depth;
            Q.push(parent);
            // cout << "    " << parent << ": new depth " << depth << endl;
          }
        }
      }
    }
  }
}

int main() { IO;
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<node> G(n + 1);
    while (m--) {
      int a, b;
      cin >> a >> b;
      G[a].children.push_back(b);
      G[b].parents.push_back(a);
    }

    calculate_depth(G, 1);
    update_depth(G);
    for (int i = 1; i <= n; ++i) {
      if (i > 1) cout << " ";
      cout << G[i].depth_reached;
    }
    cout << endl;
  }

  return 0;
}
