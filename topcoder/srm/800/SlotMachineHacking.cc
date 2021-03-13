#include<bits/stdc++.h>
using namespace std;

class SlotMachineHacking {
 public:
  int win(vector <string> reels, vector <int> steps) {
    const int n = reels.size();
    for (int i = 0; i < n; ++i) {
      steps[i] = steps[i] % reels[i].size();
    }

    vector<int> state(n);
    hash h;

    while (h.add(state) == true) {
      for (int i = 0; i < n; ++i) {
        state[i] += steps[i];
        if (state[i] >= reels[i].size()) {
          state[i] -= reels[i].size();
        }
      }
      bool jackpot = true;
      for (int i = 0; i < n; ++i) {
        if (reels[i][state[i]] != 'c') {
          jackpot = false;
          break;
        }
      }
      if (jackpot) {
        return h.size() - 1;
      }
    }

    return -1;
  }

 private:
  struct hash {
    bool add(vector<int> values) {
      int mask = 0;
      for (int i = 0; i < values.size(); ++i) {
        mask |= values[i] << (i * 4);
      }
      auto it = S.begin();
      bool ok;
      tie(it, ok) = S.insert(mask);
      return ok;
    }

    int size() const {
      return S.size();
    }

    set<int> S;
  };
};
