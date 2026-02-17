#include <iostream>

using namespace std;

int n[1000000];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int cnt = 0;
  int x = 0;
  int input = 0;
  int answer = 0;

  cin >> cnt;

  for (int i = 0; i < cnt; i++) {

    cin >> input;
    n[input - 1]++;
  }

  cin >> x;

  for (int i = 0; (i < x) && (i < sizeof(n) / sizeof(int)); i++) {
    if (n[i] > 0 && (x - (i + 1) - 1 >= 0) && (x - (i + 1) - 1 < 1000000) &&
        n[x - (i + 1) - 1] > 0) {
      answer++;
    }
  }

  cout << answer / 2;

  return 0;
}