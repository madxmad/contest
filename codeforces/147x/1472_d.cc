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

    vector<int> even(1, 0), odd(1, 0);
    for (int i = 0; i < n; ++i) {
      int number;
      cin >> number;

      if (number & 1) {
        odd.push_back(number);
      } else {
        even.push_back(number);
      }
    }

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    long long alice = 0, bob = 0;
    for (int i = 0; i < n; ++i) {
      int number;
      if (even.back() > odd.back()) {
        number = even.back();
        even.pop_back();
      } else {
        number = odd.back();
        odd.pop_back();
      }

      if (number & 1 && i & 1) {
        bob += number;
      } else if (!(number & 1) && !(i & 1)) {
        alice += number;
      }
    }

    if (alice > bob) {
      cout << "Alice\n";
    } else if (alice < bob) {
      cout << "Bob\n";
    } else {
      cout << "Tie\n";
    }
  }

  return 0;
}
