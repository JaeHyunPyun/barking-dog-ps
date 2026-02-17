#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int numArray[3];

  for (int i = 0; i < 3; i++) {
    cin >> numArray[i];
  }

  for (int i = 0; i < 2; i++) {
    for (int j = i + 1; j < 3; j++) {
      if (numArray[i] > numArray[j]) {
        int temp = numArray[i];
        numArray[i] = numArray[j];
        numArray[j] = temp;
      }
    }
  }

  for (int i = 0; i < 3; i++) {
    cout << numArray[i] << " ";
  }

  return 0;
}