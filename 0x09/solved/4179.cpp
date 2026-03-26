#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>

using namespace std;

#define X first
#define Y second

int R, C;

char board[1002][1002];
int vis1[1002][1002];
int vis2[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> R >> C;

  queue<pair<int, int>> q1; // for fire
  queue<pair<int, int>> q2; // for jihoon

  int ans = 2000;

  for (int i = 0; i < R; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < C; j++) {
      board[i][j] = s[j];

      if (board[i][j] == '#') {
        vis1[i][j] = -1;
        vis2[i][j] = -1;
      }

      if (board[i][j] == 'F') {
        q1.push({i, j});
        vis1[i][j] = 1;
      }

      if (board[i][j] == 'J') {
        q2.push({i, j});
        vis2[i][j] = 1;
      }
    }
  }

  // fire bfs
  while (!q1.empty()) {
    pair<int, int> cur = q1.front();
    q1.pop();

    for (int dir = 0; dir < sizeof(dx) / sizeof(int); dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if (nx < 0 || nx >= R || ny < 0 || ny >= R)
        continue;

      if (vis1[nx][ny] != 0)
        continue;

      vis1[nx][ny] = vis1[cur.X][cur.Y] + 1;
      q1.push({nx, ny});
    }
  }

  // J bfs
  while (!q2.empty()) {
    pair<int, int> cur = q2.front();
    q2.pop();

    for (int dir = 0; dir < sizeof(dx) / sizeof(int); dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
        int cand = vis2[cur.X][cur.Y];
        ans = min(ans, cand);
        continue;
      }

      if (vis2[nx][ny] != 0)
        continue;

      int j_est = vis2[cur.X][cur.Y] + 1;

      if (j_est < vis1[nx][ny] || vis1[nx][ny] == 0) {
        vis2[nx][ny] = j_est;
        q2.push({nx, ny});
      } else {
        vis2[nx][ny] = -1;
      }
    }
  }

  if (ans >= 2000) {
    cout << "IMPOSSIBLE";
  } else {
    cout << ans;
  }

  return 0;
}