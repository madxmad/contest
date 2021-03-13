#include<bits/stdc++.h>
using namespace std;

class TIEFighterAssembly {
 public:
  int assemble(string parts) {
    int a = count(parts.begin(), parts.end(), '|') / 2;
    int b = count(parts.begin(), parts.end(), '-') / 2;
    int c = count(parts.begin(), parts.end(), 'O');
    return min({a, b, c});
  }
};
