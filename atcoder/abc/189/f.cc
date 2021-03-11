#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'
const double eps = 1e-6;

int main() { IO;
  int n, m, k;
  cin >> n >> m >> k;

  vector<valarray<double>> board(n + 1 + m, valarray<double>(2));
  for (int i = 0; i < k; ++i) {
    int hole;
    cin >> hole;
    board[hole][1] = 1;
  }

  valarray<double> sum(2);
  for (int i = n - 1; i >= 0; --i) {
    sum += board[i + 1];
    sum -= board[i + 1 + m];
    if (!board[i][1]) {
      board[i] = sum / m + valarray<double>({1., 0.});
    }
  }

  if (fabs(board[0][1] - 1) < eps) {
    cout << -1 << endl;
    return 0;
  }

  double ans = board[0][0] / (1. - board[0][1]);
  cout << setprecision(4) << fixed << ans << endl;

  return 0;
}
