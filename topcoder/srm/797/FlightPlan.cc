#include<bits/stdc++.h>
using namespace std;

class FlightPlan {
  const bool debug = false;
  const long long inf = 1LL << 60;
  const vector<pair<int, int>> delta {{ 1, 0},
                                      { 0, 1},
                                      {-1, 0},
                                      { 0,-1}};

  struct state {
    int row, col, altitude;
    long long cost;
    bool operator < (const state& other) const {
      return cost > other.cost;
    }
  };

  int get_index(int row, int col, int r, int c) {
    return row * c + col;
  }

  bool is_valid(int x, int n) {
    return 0 <= x && x < n;
  }

  map<int, int> calculate_index_altitude(vector<int> h) {
    sort(h.begin(), h.end());
    h.erase(unique(h.begin(), h.end()), h.end());
    map<int, int> index_altitude;
    for (int i = 0; i < h.size(); ++i) {
      index_altitude[h[i]] = i;
      if (debug) cout << "altitude " << h[i] << " -> "  << i << endl;
    }

    return index_altitude;
  }

 public:
  long long fly(int r, int c, vector <int> h, int cup, int cdn, int clr) {
    priority_queue<state> PQ;
    PQ.push({0, 0, h[0], 0LL});

    map<int, int> index_altitude = calculate_index_altitude(h);
    const int sz_index = index_altitude.size();
    vector<vector<vector<long long>>> total_cost(r, vector<vector<long long>>(c, vector<long long>(sz_index, inf)));
    total_cost[0][0][index_altitude[h[0]]] = 0;

    long long ans = inf;
    while (!PQ.empty()) {
      state cur = PQ.top();
      PQ.pop();
      if (debug) cout << "current state: (" << cur.row << "," << cur.col << "," << cur.altitude
                      << "): $" << cur.cost << endl;

      if (cur.row == r - 1 && cur.col == c - 1) {
        long long delta_altitude = cur.altitude - h[get_index(cur.row, cur.col, r, c)];
        long long cost = cur.cost + delta_altitude * cdn;
        ans = min(ans, cost);
        if (debug) cout << "STOP! down " << delta_altitude << endl;
        continue;
      }

      for (auto d : delta) {
        const int row = cur.row + d.first;
        const int col = cur.col + d.second;

        if (!is_valid(row, r) || !is_valid(col, c)) continue;
        int altitude = max(cur.altitude, h[get_index(row, col, r, c)]);
        long long delta_altitude = altitude - cur.altitude;
        long long cost = cur.cost + clr + delta_altitude * cup;
        if (total_cost[row][col][index_altitude[altitude]] <= cost) continue;
        total_cost[row][col][index_altitude[altitude]] = cost;
        PQ.push({row, col, altitude, cost});
        if (debug) cout << "  go to : (" << row << "," << col << "," << altitude
                        << "): $" << cost << endl;
      }
    }

    return ans;
  }
};
