#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int input = 0;
  int multiplyResult = 1;
  int zeroToNine[10];
  fill(zeroToNine, zeroToNine + 10, 0);

  for (int i = 0; i < 3; i++) {
    cin >> input;
    multiplyResult *= input;
  }

  while (true) {
    if (multiplyResult == 0) {
      break;
    }
    zeroToNine[multiplyResult % 10]++;

    multiplyResult /= 10;
  }

  for (int i = 0; i < sizeof(zeroToNine) / sizeof(int); i++) {
    cout << zeroToNine[i] << "\n";
  }
}
