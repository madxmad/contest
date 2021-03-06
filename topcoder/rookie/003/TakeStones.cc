#include<bits/stdc++.h>
using namespace std;

class TakeStones {
public:
  string result(int stonePile, int maxStones) {
    vector<int> pile(stonePile + 1);
    for (int pos = 1; pos < pile.size(); ++pos) {
      pile[pos] = 0;
      for (int delta = 1; delta <= min(maxStones, pos); ++delta) {
        if (pile[pos - delta] == 0) {
          pile[pos] = 1;
          break;
        }
      }
    }
    return pile[stonePile] ? "WIN" : "LOSE";
  }
};
