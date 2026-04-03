#include <iostream>

using namespace std;

int cnt_zero;
int cnt_one;
int cnt_minus;

int arr[2200][2200];

void search(int len, int r, int c) {
  if (len == 0)
    return;

  // 갯수 세기
  int temp_zero = 0;
  int temp_one = 0;
  int temp_minus = 0;
  int total = len * len;

  for (int i = r; i < r + len; i++) {
    for (int j = c; j < c + len; j++) {
      int cur = arr[i][j];
      if (cur == 0) {
        temp_zero++;
      } else if (cur == 1) {
        temp_one++;
      } else if (cur == -1) {
        temp_minus++;
      }
    }
  }

  if (temp_zero == total) {
    cnt_zero++;
    return;
  } else if (temp_one == total) {
    cnt_one++;
    return;
  } else if (temp_minus == total) {
    cnt_minus++;
    return;
  }

  // 분할 정복
  for (int i = r; i < r + len; i = i + len / 3) {
    for (int j = c; j < c + len; j = j + len / 3) {
      search(len / 3, i, j);
    }
  }
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> arr[i][j];
    }
  }

  search(N, 0, 0);

  cout << cnt_minus << "\n" << cnt_zero << "\n" << cnt_one;

  return 0;
}
