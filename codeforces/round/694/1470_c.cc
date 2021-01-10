#include <bits/stdc++.h>
using namespace std;

int query(int index) {
  cout << "? " << index << endl;
  int value;
  cin >> value;
  return value;
}

int main() {
  int n, k;
  cin >> n >> k;

  int index = 1;
  int value;
  for (int size = 1; ; size += 2) {
    index = (index + size) % n;
    if (!index) index = n;
    value = query(index);
    if (value != k) {
      break;
    }
  }

  while (value != k) {
    bool left = value < k;
    for (int size = 1; ; size += 1) {
      if (left) index = (index + size) % n;
      if (!left) index = (index - size + n) % n;
      if (!index) index = n;
      value = query(index);
      if (left && value >= k) break;
      if (!left && value <= k) break;
    }
  }

  cout << "! " << index << endl;

  return 0;
}
