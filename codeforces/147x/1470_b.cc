#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

auto generate_sieve(int maxn) {
  vector<int> primes;
  vector<int> sieve(maxn + 1, 0);

  for (int p = 2; p <= maxn; ++p) {
    if (sieve[p] == 0) {
      sieve[p] = p;
      primes.push_back(p);
    }

    for (int k = 0; k < primes.size() && primes[k] <= sieve[p] && p * primes[k] <= maxn; ++k) {
      sieve[p * primes[k]] = primes[k];
    }
  }

  return sieve;
}

int max_value(const map<int, int>& counter) {
  auto cmp = [](const auto& a, const auto& b) {
    return a.second < b.second;
  };

  auto it = max_element(counter.begin(), counter.end(), cmp);
  return it->second;
}

int main() { IO;
  auto sieve = generate_sieve(1000000);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto& x : v) {
      cin >> x;
    }

    map<int, int> counter;
    for (auto& x : v) {
      map<int, int> factor;
      while (x > 1) {
        int p = sieve[x];
        x /= p;
        ++factor[p];
      }

      for (auto& [p, cnt] : factor) {
        if (cnt & 1) {
          x *= p;
        }
      }
      ++counter[x];
    }

    vector<int> ans(2);
    ans[0] = max_value(counter);
    for (auto& [x, cnt] : counter) {
      if (x != 1 && !(cnt & 1)) {
        counter[1] += cnt;
      }
    }
    ans[1] = max_value(counter);

    int q;
    cin >> q;

    while (q--) {
      long long w;
      cin >> w;
      cout << ans[!!w] << endl;
    }
  }

  return 0;
}
