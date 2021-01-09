#include<bits/stdc++.h>
using namespace std;

class BuyOneGetOneFree {
 public:
  int buy(vector <int> prices) {
    sort(prices.begin(), prices.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < prices.size(); i += 2) {
      ans += prices[i];
    }

    return ans;
  }
};
