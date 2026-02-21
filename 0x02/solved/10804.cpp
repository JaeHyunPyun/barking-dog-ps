#include <algorithm>
#include <iostream>

using namespace std;

void changeNumber(int start, int mid, int end, int num[]) {
  for (int i = start, j = end; i <= mid; i++, j--) {
    swap(num[i], num[j]);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int num[20] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

  int start = 0;
  int end = 0;
  int mid = 0;

  for (int i = 0; i < 10; i++) {
    cin >> start >> end;
    start -= 1;
    end -= 1;
    mid = (start + end) / 2;
    changeNumber(start, mid, end, num);
  }

  for (int i = 0; i < 20; i++) {
    cout << num[i] << " ";
  }

  return 0;
}