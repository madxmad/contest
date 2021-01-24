#include<bits/stdc++.h>
using namespace std;

class LogiciansAndBeer {
 public:
  int bringBeer(string r) {
    auto no = find(r.begin(), r.end(), '-');
    if (no != r.end() && count(no, r.end(), '-') != distance(no, r.end())) return -1;
    if (count(r.begin(), r.end(), '+') > 1) return -1;
    if (count(r.begin(), r.end(), '+') == 1 && r.back() != '+') return -1;
    if (r.back() == '?') return -1;
    return r.size() - count(r.begin(), r.end(), '-');
  }
};
