#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int num1 = 0;
  int num2 = 0;
  int num3 = 0;

  int num4 = 0;
  int num5 = 0;
  int num6 = 0;

  cin >> num1 >> num2 >> num3;

  num4 = min({num1, num2, num3});
  num6 = max({num1, num2, num3});
  num5 = num1 + num2 + num3 - num4 - num6;

  cout << num4 << " " << num5 << " " << num6;

  return 0;
}