#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

int main() { IO;
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for (auto& x : a) cin >> x;
  for (auto& x : b) cin >> x;

  int product = inner_product(a.begin(), a.end(), b.begin(), 0);
  cout << (product == 0 ? "Yes" : "No") << endl;

  return 0;
}
