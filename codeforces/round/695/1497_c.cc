#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define endl '\n'

long long solve(vector<long long> A, vector<long long> B, vector<long long> C) {
  long long total_a = accumulate(A.begin(), A.end(), 0LL);
  long long total_b = accumulate(B.begin() + 1, B.end(), 0LL);
  long long total_c = accumulate(C.begin() + 1, C.end(), 0LL);

  vector<long long> ans(3);
  ans[0] = -B[0] + total_c - C[0] + total_b;
  ans[1] = -B[0] - total_b + C[0] + total_c;
  ans[2] = -C[0] - total_c + B[0] + total_b;
  // cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;

  return *max_element(ans.begin(), ans.end()) + total_a;
}

int main() { IO;
  int a, b, c;
  cin >> a >> b >> c;

  vector<long long> A(a), B(b), C(c);
  for (auto& x : A) cin >> x;
  for (auto& x : B) cin >> x;
  for (auto& x : C) cin >> x;

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());

  vector<long long> ans(3);
  ans[0] = solve(A, B, C);
  ans[1] = solve(B, A, C);
  ans[2] = solve(C, A, B);

  cout << *max_element(ans.begin(), ans.end()) << endl;;

  return 0;
}
