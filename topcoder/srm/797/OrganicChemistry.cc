#include<bits/stdc++.h>
using namespace std;

class OrganicChemistry {
 public:
  int countHydrogens(string atoms, vector <int> x, vector <int> y) {
    const int n = atoms.size();
    vector<int> cnt(atoms.size());

    for (int i = 0; i < n; ++i) {
      switch (atoms[i]) {
      case 'H': cnt[i] = 1; break;
      case 'O': cnt[i] = 2; break;
      case 'N': cnt[i] = 3; break;
      case 'C': cnt[i] = 4; break;
      }
    }

    const int m = x.size();
    for (int i = 0; i < m; ++i) {
      --cnt[x[i]];
      --cnt[y[i]];
    }

    int ans = accumulate(cnt.begin(), cnt.end(), 0);
    return ans;
  }
};
