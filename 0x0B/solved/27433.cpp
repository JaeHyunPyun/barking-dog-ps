#include <iostream>

using namespace std;

using ll = long long;

ll factorial(int N) {
  if (N == 0)
    return 1;

  return N * factorial(N - 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  cout << factorial(N);

  return 0;
}