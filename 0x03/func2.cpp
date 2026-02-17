#include <iostream>

using namespace std;

int func2(int arr[], int N) {

  int numCount[101];
  fill(numCount, numCount + 101, 0);

  for (int i = 0; i < N; i++) {
    numCount[arr[i]]++;
  }

  for (int i = 0; i < sizeof(numCount) / sizeof(int); i++) {
    if ((i != (100 - i) && (numCount[i] == 1) && (numCount[100 - i] == 1))) {
      return 1;
    }
  }

  return 0;
}

int main() {

  int arr[3][4] = {{1, 52, 48}, {50, 42}, {4, 13, 63, 87}};
  int n[3] = {3, 2, 4};
  int ans[3] = {1, 0, 1};

  for (int i = 0; i < 3; i++) {
    int result = func2(arr[i], n[i]);
    cout << "result : " << result;

    cout << "TC #" << i << '\n';
    cout << "expected : " << ans[i] << " result : " << result;
    if (ans[i] == result)
      cout << " ... Correct!\n";
    else
      cout << " ... Wrong!\n";
  }

  return 0;
}