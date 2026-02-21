#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int oddSum = 0;
  int minOdd = 101;
  int input = 0;

  for (int i = 0; i < 7; i++) {
    cin >> input;

    if (input % 2 == 0) {
      continue;
    }

    oddSum += input;

    if (input <= minOdd) {
      minOdd = input;
    }
  }

  if (oddSum == 0) {
    cout << -1;
  } else {
    cout << oddSum << "\n";
    cout << minOdd;
  }

  return 0;
}