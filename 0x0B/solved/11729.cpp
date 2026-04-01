#include <iostream>

using namespace std;

void func(int a, int b, int n) {
  if (n == 1) {
    cout << a << ' ' << b << '\n';
    return;
  }

  func(a, 6 - a - b, n - 1);
  cout << a << ' ' << b << "\n";
  func(6 - a - b, b, n - 1);
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int k;
  cin >> k;

  int cnt = 1;
  int j = k - 1;
  while (j--) {
    cnt = 2 * cnt + 1;
  }

  cout << cnt << "\n";

  func(1, 3, k);

  return 0;
}