#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  queue<int> Q;

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    Q.push(i + 1);
  }

  while (Q.size() != 1) {
    Q.pop();

    int f = Q.front();
    Q.push(f);
    Q.pop();
  }

  cout << Q.front() << "\n";

  return 0;
}