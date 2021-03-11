#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

using point = valarray<long long>;

struct matrix {
  matrix operator*(const matrix& other) {
    point ret(9);
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        point row = values[slice(3 * i, 3, 1)];
        point col = other.values[slice(j, 3, 3)];
        point mult = row * col;
        ret[3 * i + j] = mult.sum();
      }
    }
    return matrix{ret};
  }

  point operator*(const point& other) {
    point ret(3);
    for (int i = 0; i < 3; ++i) {
      point row = values[slice(3 * i, 3, 1)];
      point mult = row * other;
      ret[i] = mult.sum();
    }
    return ret;
  }

  valarray<long long> values;
};

int main() { IO;
  int n;
  cin >> n;

  vector<point> points(n, point(1, 3));
  for (auto& point : points) {
    cin >> point[0] >> point[1];
  }

  int m;
  cin >> m;

  vector<int> q(m), p(m);
  for (int i = 0; i < q.size(); ++i) {
    cin >> q[i];
    if (q[i] > 2) {
      cin >> p[i];
    }
  }

  int k;
  cin >> k;

  vector<int> a(k), b(k);
  for (int i = 0; i < a.size(); ++i) {
    cin >> a[i] >> b[i];
  }

  matrix t{{1, 0, 0, 0, 1, 0, 0, 0, 1}};
  vector<matrix> origins(m + 1);
  origins[0] = t;

  for (int i = 0; i < q.size(); ++i) {
    const long long p2 = 2 * p[i];
    switch (q[i]) {
    case 1: t = matrix {{0, 1, 0, -1, 0, 0, 0, 0, 1}} * t; break;
    case 2: t = matrix {{0, -1, 0, 1, 0, 0, 0, 0, 1}} * t; break;
    case 3: t = matrix {{-1, 0, p2, 0, 1, 0, 0, 0, 1}} * t; break;
    case 4: t = matrix {{1, 0, 0, 0, -1, p2, 0, 0, 1}} * t; break;
    }
    origins[i + 1] = t;
  }

  for (int i = 0; i < a.size(); ++i) {
    auto result = origins[a[i]] * points[b[i] - 1];
    cout << result[0] << " " << result[1] << endl;
  }

  return 0;
}
