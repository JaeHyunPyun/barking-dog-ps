#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int zeroToNine[10];
  fill(zeroToNine, zeroToNine + 10, 0);

  int number = 0;
  cin >> number;

  while (number > 0) {
    zeroToNine[number % 10]++;
    number /= 10;
  }

  if (zeroToNine[6] != 0 || zeroToNine[9] != 0) {
    int sum = zeroToNine[6] + zeroToNine[9];
    int slice = sum / 2;
    int residue = sum - slice;
    zeroToNine[6] = slice;
    zeroToNine[9] = residue;
  }

  int max = *max_element(zeroToNine, zeroToNine + 10);
  cout << max << endl;

  return 0;
}