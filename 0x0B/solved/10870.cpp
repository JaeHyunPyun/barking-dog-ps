#include <iostream>

using namespace std;

int fivonacci(int N) {

  if (N == 0)
    return 0;
  if (N == 1)
    return 1;

  return fivonacci(N - 1) + fivonacci(N - 2);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  cout << fivonacci(N);

  return 0;
}