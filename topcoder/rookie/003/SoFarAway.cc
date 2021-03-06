#include<bits/stdc++.h>
using namespace std;

struct state {
  pair<int, int> cell;
  int moves;
};

const vector<pair<int, int>> delta = {{-1, 0},
                                      { 0,-1},
                                      { 1, 0},
                                      { 0, 1}};

class SoFarAway {
public:
  int distance(const vector <string> plan) {
    int n = plan.size();
    int m = plan[0].size();

    auto start = find_cell(plan, 'S');
    auto finish = find_cell(plan, 'D');

    queue<state> Q;
    Q.push({start, 0});

    set<pair<int,int>> mark;
    mark.insert(start);

    while (!Q.empty()) {
      auto current = Q.front().cell;
      auto moves = Q.front().moves;
      Q.pop();

      if (current == finish) {
        return moves;
      }

      for (auto d : delta) {
        auto next = current;
        next.first += d.first;
        next.second += d.second;

        if (!is_valid(n, m, next)) continue;
        if (mark.count(next)) continue;
        if (plan[next.first][next.second] == 'X') continue;

        mark.insert(next);
        Q.push({next, moves + 1});
      }
    }

    return -1;
  }

private:
  pair<int,int> find_cell(const vector <string> plan, char ch) {
    for (int col = 0; col < plan.size(); ++col) {
      for (int row = 0; row < plan[0].size(); ++row) {
        if (plan[col][row] == ch) {
          return {col, row};
        }
      }
    }
    return {};
  }

  bool is_valid(int cols, int rows, pair<int, int> cell) {
    if (cell.first  < 0 || cols <= cell.first) return false;
    if (cell.second < 0 || rows <= cell.second) return false;
    return true;
  }

};
