#include<bits/stdc++.h>
using namespace std;

class PlanningTrips {
 public:
  int find(int base, vector <int> num) {
    map<int, int> values;
    for (auto value : num) {
      ++values[value];
    }

    for (auto it = values.begin(); it != values.end();) {
      int key = it->first;
      int cnt = it->second;

      int r = cnt % base;
      int d = cnt / base;

      if (d) {
        values[key + 1] += d;
      }

      if (r) {
        values[key] = r;
        ++it;
      } else {
        values.erase(it++);
      }
    }

    int ans = values.rbegin()->first;
    if (values.size() > 1 || values[ans] > 1) {
      ++ans;
    }

    return ans;
  }
};
