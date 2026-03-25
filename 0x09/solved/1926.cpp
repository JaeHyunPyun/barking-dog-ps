#include <iostream>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;

int board[502][502];
int vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  int pictCount = 0;
  int maxPictSize = 0;

  queue<pair<int, int>> Q;

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int curPictSize = 0;
      if (vis[i][j] != 1 && board[i][j] == 1) {
        pair<int, int> init = {i, j};
        vis[i][j] = 1;
        Q.push(init);

        pictCount++;
      }

      while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        curPictSize++;

        for (int dir = 0; dir < sizeof(dx) / sizeof(int); dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];

          if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
          if (vis[nx][ny] == 1 || board[nx][ny] != 1)
            continue;

          vis[nx][ny] = 1;
          Q.push({nx, ny});
        }
      }

      if (curPictSize > maxPictSize) {
        maxPictSize = curPictSize;
      }
    }
  }

  cout << pictCount << "\n";
  cout << maxPictSize;

  return 0;
}