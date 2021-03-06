#include<bits/stdc++.h>
using namespace std;

class FriendFinder {
public:
  int distance(string line) {
    int f = line.find('F');
    int s = line.find('S');
    return abs(f - s);
  }
};
