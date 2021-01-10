#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

int main() { IO;
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<int> friends(n);
    for (auto& f : friends) {
      cin >> f;
      f--;
    }

    vector<int> presents(m);
    for (auto& p : presents) {
      cin >> p;
    }

    sort(friends.begin(), friends.end(), greater<int>());

    long long ans = 0;
    int current_present = 0;

    for (auto& current_friend : friends) {
      if (current_present >= current_friend) {
        ans += presents[current_friend];
      }  else {
        ans += presents[current_present];
        ++current_present;
      }
    }

    cout << ans << endl;
  }

  return 0;
}
