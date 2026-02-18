#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int zeroCount[3] = {
      0,
  };
  int input = -1;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> input;

      if (input == 0) {
        zeroCount[i]++;
      }
    }
  }

  for (int i = 0; i < 3; i++) {
    if (zeroCount[i] == 0) {
      cout << "E";
    } else if (zeroCount[i] == 1) {
      cout << "A";
    } else if (zeroCount[i] == 2) {
      cout << "B";
    } else if (zeroCount[i] == 3) {
      cout << "C";
    } else if (zeroCount[i] == 4) {
      cout << "D";
    }
    cout << "\n";
  }

  return 0;
}