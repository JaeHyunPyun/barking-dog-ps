#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long A = 0;
  long B = 0;
  long count = 0;
  long start = 0;
  long end = 0;

  cin >> A >> B;

  if (A > B) {
    start = B;
    end = A;
  } else {
    start = A;
    end = B;
  }

  if (A != B) {
    count = end - start - 1;
  }

  cout << count << "\n";

  for (long i = start + 1; i < end; i++) {
    cout << i << " ";
  }

  return 0;
}