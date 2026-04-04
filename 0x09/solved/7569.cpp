#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int days;
// h, N, M
int board[105][105][105];
int visit[105][105][105];

int M, N, H;

int dh[2] = {1, -1};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool check_has_zero() {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < M; k++) {
        if (visit[i][j][k] == 0)
          return true;
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> M >> N >> H;

  queue<tuple<int, int, int>> Q;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < M; k++) {
        cin >> board[i][j][k];

        // 초기값 넣기
        if (board[i][j][k] == 1 && visit[i][j][k] == 0) {
          visit[i][j][k] = 1;
          Q.push({i, j, k});
        }

        if (board[i][j][k] == -1) {
          visit[i][j][k] = -1;
        }
      }
    }
  }

  if (!check_has_zero()) {
    cout << 0;
    return 0;
  }

  while (!Q.empty()) {
    tuple<int, int, int> cur = Q.front();
    Q.pop();
    int cur_z = get<0>(cur);
    int cur_x = get<1>(cur);
    int cur_y = get<2>(cur);
    days = max(days, visit[cur_z][cur_x][cur_y]);

    // 상하좌우 이동
    for (int dir = 0; dir < sizeof(dx) / sizeof(int); dir++) {
      int nx = cur_x + dx[dir];
      int ny = cur_y + dy[dir];

      if (nx < 0 || nx >= N || ny < 0 || ny >= M)
        continue;
      if (board[cur_z][nx][ny] != 0 || visit[cur_z][nx][ny] != 0)
        continue;

      visit[cur_z][nx][ny] = visit[cur_z][cur_x][cur_y] + 1;
      Q.push({cur_z, nx, ny});
    }

    // 위아래 이동
    for (int dir = 0; dir < sizeof(dh) / sizeof(int); dir++) {
      int nh = cur_z + dh[dir];

      if (nh < 0 || nh >= H)
        continue;
      if (board[nh][cur_x][cur_y] != 0 || visit[nh][cur_x][cur_y] != 0)
        continue;

      visit[nh][cur_x][cur_y] = visit[cur_z][cur_x][cur_y] + 1;
      Q.push({nh, cur_x, cur_y});
    }
  }

  if (check_has_zero()) {
    cout << -1;
    return 0;
  } else {
    cout << days - 1;
  }

  return 0;
}