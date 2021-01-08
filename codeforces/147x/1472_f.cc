#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

vector<vector<vector<int>>> dp(1000000, vector<vector<int>>(2, vector<int>(2)));

struct cell {
  int row, col;
};

bool solve(int index, int up, int down, const vector<vector<int>>& board) {
  if (index < 0) {
    return true;
  }

  if (dp[index][up][down] == -1) {
    bool ret = false;
    if (up == down) {
      ret = solve(index - 1, board[0][index - 1], board[1][index - 1], board);
    } else if (!up) {
      ret = (board[0][index - 1] == 0) && solve(index - 1, 1, board[1][index - 1], board);
    } else if (!down) {
      ret = (board[1][index - 1] == 0) && solve(index - 1, board[0][index - 1], 1, board);
    }

    dp[index][up][down] = ret;
  }

  return dp[index][up][down];
}

int main() { IO;
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<cell> blocked(m);
    vector<int> columns;
    for (auto& cell : blocked) {
      cin >> cell.row >> cell.col;
      --cell.row;
      --cell.col;
      columns.push_back(--cell.col);
    }
    sort(columns.begin(), columns.end());
    columns.erase(unique(columns.begin(), columns.end()), columns.end());

    map<int, int> col_map;
    col_map[columns.front()] = 0;
    for (int i = 1; i < columns.size(); ++i) {
      int diff = columns[i] - columns[i - 1];
      if (diff & 1) {
        col_map[columns[i]] = col_map[columns[i - 1]] + 1;
      } else {
        col_map[columns[i]] = col_map[columns[i - 1]] + 2;
      }
    }

    int new_n = 0;
    for (auto& cell : blocked) {
      // cout << cell.col << " -> " << col_map[cell.col] << endl;
      cell.col = col_map[cell.col];
      new_n = max(new_n, cell.col);
    }
    ++new_n;

    vector<vector<int>> board(2, vector<int>(new_n, 0));
    for (int i = 0; i < new_n; ++i) {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          dp[i][j][k] = -1;
        }
      }
    }

    for (const auto& cell : blocked) {
      board[cell.row][cell.col] = 1;
      // cout << cell.row << " " << cell.col << endl;
    }

    bool ans = solve(new_n - 1, board[0][new_n - 1], board[1][new_n - 1], board);
    cout << (ans ? "YES" : "NO") << endl;
  }

  return 0;
}
