#include <iostream>

using namespace std;

int nSquare(int a, int b) {
  if (b == 0) {
    return 1;
  }

  return a * nSquare(a, b - 1);
}

int func(int a, int b, int m) {
  int val = 1;
  while (b--)
    val *= a % m;
  return val % m;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // int a, b, m;

  // cin >> a >> b >> m;

  // cout << nSquare(a, b) % m;

  cout << func(6, 100, 5);

  return 0;
}