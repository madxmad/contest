#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

int main() { IO;
  int x, y;
  cin >> x >> y;

  bool is_possible = min(x, y) + 3 > max(x, y);
  cout << (is_possible ? "Yes" : "No") << endl;

  return 0;
}
