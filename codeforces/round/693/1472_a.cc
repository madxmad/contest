#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

int main() { IO;
  int t;
  cin >> t;

  while (t--) {
    int w, h, n;
    cin >> w >> h >> n;

    int a = 1;
    while ((w & 1) == 0) {
      w >>= 1;
      a <<= 1;
    }
    int b = 1;
    while ((h & 1) == 0) {
      h >>= 1;
      b <<= 1;
    }

    if (a * b >= n) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
