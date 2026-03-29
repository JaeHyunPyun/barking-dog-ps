#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int vis[100002];

int dx[3] = {-1, 1, 2};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K;

  cin >> N >> K;

  queue<int> q;

  fill(vis, vis + 100002, -1);

  q.push(N);
  vis[N] = 0;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (cur == K) {
      cout << vis[cur];
      return 0;
    }

    for (int dir = 0; dir < sizeof(dx) / sizeof(int); dir++) {
      int nx = cur;
      int operand = dx[dir];
      if (operand == 2) {
        nx = nx * operand;
      } else {
        nx = nx + operand;
      }

      if (nx < 0 || nx > 100000)
        continue;
      if (vis[nx] != -1)
        continue;

      vis[nx] = vis[cur] + 1;
      q.push(nx);
    }
  }

  return 0;
}