#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int inputSize = 0;
  int targetNumber = 0;
  int input = 0;

  cin >> inputSize >> targetNumber;

  for (int i = 0; i < inputSize; i++) {
    cin >> input;

    if (input < targetNumber) {
      cout << input << " ";
    }
  }
}