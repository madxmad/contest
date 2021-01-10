#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

int f(int x) {
  int s = 0;
  while (x) {
    s += x % 10;
    x /= 10;
  }

  return s;
}

int main() { IO;
  int a, b;
  cin >> a >> b;

  cout << max(f(a), f(b)) << endl;

  return 0;
}
