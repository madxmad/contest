#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

int main() { IO;
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<long long> board(n);
    for (auto& x : board) {
      cin >> x;
    }

    reverse(board.begin(), board.end());
    for (int i = 0; i < n; ++i) {
      if (board[i] <= i) {
        board[i] += board[i - board[i]];
      }
    }

    long long ans = *max_element(board.begin(), board.end());
    cout << ans << endl;
  }

  return 0;
}
