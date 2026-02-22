#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int inputCount = 0;
  int numA = 0;
  int numB = 0;

  cin >> inputCount;

  for (int i = 0; i < inputCount; i++) {
    cin >> numA >> numB;
    cout << numA + numB << "\n";
  }

  return 0;
}