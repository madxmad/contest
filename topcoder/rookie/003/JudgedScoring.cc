#include<bits/stdc++.h>
using namespace std;

class JudgedScoring {
public:
  int overallScore(vector <int> scores) {
    sort(scores.begin(), scores.end());
    int ans = accumulate(scores.begin(), scores.end(), 0) - scores.front() - scores.back();
    return ans;
  }
};
