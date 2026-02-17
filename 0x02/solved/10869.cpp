#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int operand1 = 0;
  int operand2 = 0;

  cin >> operand1 >> operand2;

  cout << operand1 + operand2 << "\n";
  cout << operand1 - operand2 << "\n";
  cout << operand1 * operand2 << "\n";
  cout << operand1 / operand2 << "\n";
  cout << operand1 % operand2;
  return 0;
}