#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

#define X first
#define Y second

int board[1005][1005];
int N, M; // N : 가로 , M : 세로
int days[1005][1005];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int ans = -1;
  cin >> M >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    fill(days[i], days[i] + M, -1);
  }

  queue<pair<int, int>> q;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == 1) {
        days[i][j] = 0;
        q.push({i, j});
      }
    }
  }

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    ans = max(ans, days[cur.X][cur.Y]);
    q.pop();

    for (int dir = 0; dir < sizeof(dx) / sizeof(int); dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if (nx < 0 || nx >= N || ny < 0 || ny >= M)
        continue;
      if (days[nx][ny] >= 0 || board[nx][ny] == -1)
        continue;

      days[nx][ny] = days[cur.X][cur.Y] + 1;
      q.push({nx, ny});
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] != -1 && days[i][j] < 0) {
        ans = -1;
      }
    }
  }

  cout << ans;

  return 0;
}