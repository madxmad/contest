#include<bits/stdc++.h>
using namespace std;

class MinMaxGame {
 public:
  int lastNumber(vector <int> A) {
    if (A.size() % 2) {
      return max(A.front(), A.back());
    }
    return min(A.front(), A.back());
  }
};
