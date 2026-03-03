#include <bits/stdc++.h>
using namespace std;

bool solve_problem(int m, int t, vector<int> &prefix) {
  for (int i = m; i < prefix.size(); i++) {
    int total = prefix[i] - prefix[i - m];
    if (total <= t) {
      return true;
    }
  }
  return false;
}

int main() {

  int n, t;
  cin >> n >> t;

  vector<int> books(n);
  for (int i = 0; i < n; i++) {
    cin >> books[i];
  }

  vector<int> prefix(n + 1);

  for (int i = 1; i <= n; i++) {
    prefix[i] = books[i - 1] + prefix[i - 1];
  }

  int L = 0, R = n;
  int ans = 0;
  while (L <= R) {
    int m = L + (R - L) / 2;

    if (solve_problem(m, t, prefix)) {
      ans = m;
      L = m + 1;
    } else {
      R = m - 1;
    }
  }

  cout << ans << "\n";
  return 0;
}
