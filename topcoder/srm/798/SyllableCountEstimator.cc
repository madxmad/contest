#include<bits/stdc++.h>
using namespace std;

class SyllableCountEstimator {
  static bool is_vowel(const char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
  int count_groups(const string& w) {
    int cnt = 0;
    vector<string> groups = {"au", "oa", "oo", "iou"};
    for (int i = 0; i < w.size(); ++i) {
      for (const auto& group : groups) {
        cnt += (group == w.substr(i, group.size()));
      }
    }
    return cnt;
  }
  int ends_le(const string& w) {
    int sz = w.size();
    return sz >= 3
      && !is_vowel(w[sz - 3])
      && w[sz - 2] == 'l'
      && w[sz - 1] == 'e';
  }

 public:
  int estimate(string w) {
    int ans = count_if(w.begin(), w.end(), is_vowel);
    ans -= count_groups(w);
    ans -= w.back() == 'e';
    ans += ends_le(w);
    return max(ans, 1);
  }
};
