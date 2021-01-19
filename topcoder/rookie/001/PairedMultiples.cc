#include<bits/stdc++.h>
using namespace std;

class PairedMultiples {
public:
  int selectedTotal(vector <int> values, int multiple) {
    const int n = values.size();
    set<int> S;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        if ((values[i] + values[j]) % multiple) continue;
        S.insert(i);
        S.insert(j);
      }
    }

    int ans = 0;
    for (int i : S) ans += values[i];
    return ans;
  }
};
