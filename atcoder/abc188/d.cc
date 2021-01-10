#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

int main() { IO;
  long long n, prime;
  cin >> n >> prime;

  map<long long, long long> state;
  while (n--) {
    long long a, b, c;
    cin >> a >> b >> c;

    state[a] += c;
    state[b + 1] -= c;
  }

  long long ans = 0;
  long long last_day = 0;
  long long sum_cost = 0;
  for (const auto& [current_day, cost] : state) {
    long long days = current_day - last_day;
    ans += min(sum_cost, prime) * days;
    /*cout << current_day << "(" << days << ") $" << cost
      << ": +" << min(sum_cost, prime) * days << endl;*/
    last_day = current_day;
    sum_cost += cost;
  }

  cout << ans << endl;

  return 0;
}
