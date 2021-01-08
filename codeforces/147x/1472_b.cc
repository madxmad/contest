#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

int main() { IO;
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> candies(3);
    while (n--) {
      int weight;
      cin >> weight;
      ++candies[weight];
    }

    bool is_possible = false;
    int expected = (candies[1] + 2 * candies[2]) / 2;

    for (int a = 0; a <= candies[1]; ++a) {
      int b = min((expected - a) / 2, candies[2]);
      int weight1 = a + 2 * b;
      int weight2 = candies[1] - a + 2 * (candies[2] - b);
      if (expected == weight1 && expected == weight2) {
        is_possible = true;
      }
    }

    if (is_possible) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
