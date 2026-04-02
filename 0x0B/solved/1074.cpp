#include <cmath>
#include <iostream>

using namespace std;

int visit(int N, int r, int c) {

  if (N == 0) {
    return 0;
  }

  int two_N_minus_one = pow(2, N - 1);
  int two_N = pow(2, N);

  if ((r >= 0 && r < two_N_minus_one) && (c >= 0 && c < two_N_minus_one)) {
    return visit(N - 1, r, c);
  } else if ((r >= 0 && r < two_N_minus_one) &&
             (c >= two_N_minus_one && c < two_N)) {
    return two_N_minus_one * two_N_minus_one +
           visit(N - 1, r, c - two_N_minus_one);
  } else if ((r >= two_N_minus_one && r < two_N) &&
             (c >= 0 && c < two_N_minus_one)) {
    return 2 * two_N_minus_one * two_N_minus_one +
           visit(N - 1, r - two_N_minus_one, c);
  } else if ((r >= two_N_minus_one && r < two_N) &&
             (c >= two_N_minus_one && c < two_N)) {
    return 3 * two_N_minus_one * two_N_minus_one +
           visit(N - 1, r - two_N_minus_one, c - two_N_minus_one);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, r, c;

  cin >> N >> r >> c;

  cout << visit(N, r, c);

  return 0;
}