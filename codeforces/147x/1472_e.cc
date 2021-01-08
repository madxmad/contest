#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

struct shape {
  int index, h, w;
  bool is_inv;
};

int main() { IO;
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<shape> shapes;
    for (int i = 0; i < n; ++i) {
      int h, w;
      cin >> h >> w;
      shapes.push_back(shape{i, h, w, false});
      shapes.push_back(shape{i, w, h, true});
    }

    auto sorter = [](const auto& a, const auto& b) { return tuple{a.h, a.w} < tuple{b.h, b.w}; };
    sort(shapes.begin(), shapes.end(), sorter);

    vector<int> ans(n, -1);
    optional<shape> min;

    for (int i = 0; i < shapes.size();) {
      auto& left_shape = shapes[i];
      int j = i;
      for (; j < shapes.size(); ++j) {
        auto& right_shape = shapes[j];
        if (left_shape.h != right_shape.h) {
          break;
        }

        if (min.has_value() && min->index != right_shape.index && min->w < right_shape.w) {
          ans[right_shape.index] = min->index + 1;
        }
      }

      for (; i < j; ++i) {
        auto& shape = shapes[i];
        if (shape.is_inv) {
          continue;
        }

        if (!min.has_value() || min->w > shape.w) {
          min = shape;
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      if (i) {
        cout << " ";
      }
      cout << ans[i];
    }
    cout << endl;
  }

  return 0;
}
