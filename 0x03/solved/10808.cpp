#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int alphabet[26] = {
      0,
  };

  char input[101];

  cin >> input;

  for (int i = 0; input[i] != '\0' && i < sizeof(input); i++) {
    alphabet[input[i] - 97]++;
  }

  for (int i = 0; i < sizeof(alphabet) / sizeof(int); i++) {
    cout << alphabet[i] << " ";
  }

  return 0;
}