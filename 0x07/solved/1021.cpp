#include <deque>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  deque<int> dat;

  int N, M;
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    dat.push_back(i);
  }

  int operationSum = 0;

  while (M--) {
    int T;
    cin >> T;

    int targetIndex = 0;
    for (int i = 0; i < N; i++) {
      int X = dat[i];
      if (X == T) {
        targetIndex = i;
        break;
      }
    }

    if (targetIndex == 0) {
      dat.pop_front();
    } else if (targetIndex <= (dat.size() / 2)) {
      operationSum += targetIndex;

      while (targetIndex--) {
        if (!dat.empty()) {
          int temp = dat.front();
          dat.pop_front();
          dat.push_back(temp);
        }
      }

      dat.pop_front();
    } else {
      int leftOverCount = dat.size();

      int operationCount = leftOverCount - targetIndex;
      operationSum += operationCount;

      while (operationCount--) {
        if (!dat.empty()) {
          int temp = dat.back();
          dat.pop_back();
          dat.push_front(temp);
        }
      }

      dat.pop_front();
    }
  }

  cout << operationSum;

  return 0;
}