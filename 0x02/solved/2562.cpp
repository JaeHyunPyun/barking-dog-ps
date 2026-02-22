#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int max = 0;
  int maxOrder = 0;
  int input = 0;

  for (int i = 0; i < 9; i++) {
    cin >> input;
    if (input > max) {
      max = input;
      maxOrder = i + 1;
    }
  }

  cout << max << "\n";
  cout << maxOrder;

  return 0;
}