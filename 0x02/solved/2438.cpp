#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N = 0;

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i >= j) {
        cout << "*";
      }
    }
    if (i <= N - 1) {
      cout << "\n";
    }
  }

  return 0;
}