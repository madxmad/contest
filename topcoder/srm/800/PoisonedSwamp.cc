#include<bits/stdc++.h>
using namespace std;

const int inf = 1 << 20;

class PoisonedSwamp {
 public:
  string cross(vector <string> swamp) {
    const int rows = swamp.size();
    const int cols = swamp[0].size();

    vector<vector<int>> state(rows, vector<int>(cols, inf));
    state[0][0] = 0;
    vector<pair<int, int>> delta;
    for (int i = -1; i <= 1; ++i) {
      for (int j = -1; j <= 1; ++j) {
        if (abs(i) + abs(j) != 1) continue;
        delta.push_back({i, j});
      }
    }

    for (int turn = 0; turn < 100000; ++turn) {
      vector<vector<int>> new_state(rows, vector<int>(cols, inf));
      for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
          if (state[row][col] != inf) {
            for (auto d : delta) {
              int new_row = row + d.first;
              int new_col = col + d.second;
              if (new_row < 0 || new_row >= rows) continue;
              if (new_col < 0 || new_col >= cols) continue;
              auto poison = state[row][col];
              auto next = swamp[new_row][new_col];
              auto new_poison = inf;
              if (next == '#') continue;
              if (next == '.') {
                new_poison = poison;
              } else if (next == 'S') {
                new_poison = 0;
              } else if (poison + next - '0' >= 10) {
                continue;
              } else {
                new_poison = poison + next - '0';
              }
              new_state[new_row][new_col] = min(new_poison, new_state[new_row][new_col]);
              if (new_row == rows - 1 && new_col == cols - 1) {
                return "possible";
              }
            }
          }
        }
      }
      swap(state, new_state);
    }

    return "impossible";
  }
};
