#include<bits/stdc++.h>
using namespace std;

class CoolPairsEasy {
 public:
  int count(vector <string> firstname, vector <string> lastname) {
    const int n = firstname.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i != j && firstname[i] == lastname[j]) {
          ++ans;
        }
      }
    }
    return ans;
  }
};
