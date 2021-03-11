#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

int main() { IO;
  string s;
  cin >> s;

  bool same = all_of(s.begin(), s.end(), [&s](char ch) {return ch == s.front(); } );
  cout << (same ? "Won" : "Lost") << endl;

  return 0;
}
