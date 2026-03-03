#include <bits/stdc++.h>
using namespace std;

int main() {

  double c;
  cin >> c;

  double l = 0.0;
  double r = 1e5;
  for (int i = 0; i < 40; i++) {
    double mid = l + (r - l) / 2;
    double equation = mid * mid + sqrt(mid);

    if (equation > c) {
      r = mid;
    } else {
      l = mid;
    }
  }

  cout << setprecision(10) << l << endl;
  return 0; 
}
