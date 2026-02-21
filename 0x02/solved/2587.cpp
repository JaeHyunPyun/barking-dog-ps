#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int num[5];
  int sum = 0;
  int average = 0;

  fill(num, num + 5, 0);

  for (int i = 0; i < 5; i++) {
    cin >> num[i];
    sum += num[i];
  }

  average = sum / 5;

  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 5; j++) {
      if (num[i] > num[j]) {
        int temp = num[i];
        num[i] = num[j];
        num[j] = temp;
      }
    }
  }

  cout << average << "\n";
  cout << num[2];

  return 0;
}