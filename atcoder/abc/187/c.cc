#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

int main() { IO;
  int n;
  cin >> n;

  set<string> S;
  while (n--) {
    string s;
    cin >> s;
    S.insert(s);
  }

  string ans;
  for (const auto& s : S) {
    if (S.count("!" + s)) {
      ans = s;
      break;
    }
  }

  if (!ans.size()) {
    ans = "satisfiable";
  }

  cout << ans << endl;

  return 0;
}
