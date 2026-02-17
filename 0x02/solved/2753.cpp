#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int number = 0;

  cin >> number;

  if ((number % 4 == 0) && (number % 100 != 0)) {
    cout << 1;
  } else if (number % 400 == 0) {
    cout << 1;
  } else {
    cout << 0;
  }

  return 0;
}