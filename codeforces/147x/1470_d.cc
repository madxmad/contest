#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

enum class colour { none, black, white };

struct node {
  int id;
  colour color = colour::none;
  bool visited = false;
  vector<int> children;
};

void dfs(vector<node>& G, node& current) {
  // cout << "visiting: " << current.id << endl;
  if (current.color == colour::black) {
    for (int next : current.children) G[next].color = colour::white;
    for (int next : current.children) {
      if (G[next].visited) continue;
      G[next].color = colour::white;
      G[next].visited = true;
      dfs(G, G[next]);
    }
  } else {
    for (int next : current.children) {
      if (G[next].color != colour::none) continue;
      G[next].color = colour::black;
      G[next].visited = true;
      dfs(G, G[next]);
    }
  }
}

int main() { IO;
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<node> G(n);
    while (m--) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;

      G[a].children.push_back(b);
      G[b].children.push_back(a);
      G[a].id = a + 1;
      G[b].id = b + 1;
    }

    G[0].color = colour::black;
    G[0].visited = true;
    dfs(G, G[0]);

    auto validator = [](const node& node) { return node.color != colour::none; };
    bool is_connected = all_of(G.begin(), G.end(), validator);
    if (!is_connected) {
      cout << "NO" << endl;
      continue;
    }

    vector<int> ans;
    for (const node& node : G) {
      if (node.color == colour::black) {
        ans.push_back(node.id);
      }
    }

    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (int id : ans) {
      cout << id << " ";
    }
    cout << endl;
  }

  return 0;
}
