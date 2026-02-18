#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int num1 = 0;
  int num2 = 0;
  int num3 = 0;

  cin >> num1 >> num2 >> num3;

  if (num1 == num2) {
    if (num2 == num3) {
      cout << 10000 + (num1) * 1000;
    } else {
      cout << 1000 + (num1) * 100;
    }
  } else {
    if (num1 == num3) {
      cout << 1000 + (num1) * 100;
    } else if (num2 == num3) {
      cout << 1000 + (num2) * 100;
    } else {
      cout << max({num1, num2, num3}) * 100;
    }
  }

  return 0;
}