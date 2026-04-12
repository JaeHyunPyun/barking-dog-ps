#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define X first
#define Y second

int board[102][102];
int visit[102][102];
int dist[102][102];

int N;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int cnt = 0;
  queue<pair<int, int>> q1;

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  // 1. 섬구별
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      bool new_island = false;

      if (board[i][j] != 0 && visit[i][j] == 0) {
        board[i][j] += cnt;
        visit[i][j] = 1;
        q1.push({i, j});
        new_island = true;
      }

      while (!q1.empty()) {
        pair<int, int> cur = q1.front();
        q1.pop();

        for (int dir = 0; dir < sizeof(dx) / sizeof(int); dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];

          if (nx < 0 || nx >= N || ny < 0 | +ny >= N)
            continue;
          if (board[nx][ny] == 0 || visit[nx][ny] == 1)
            continue;

          board[nx][ny] += cnt;
          visit[nx][ny] = 1;
          q1.push({nx, ny});
        }
      }

      if (new_island == true) {
        cnt++;
      }
    }
  }

  int min_dist = 10005;
  // 2. 섬 순회하면서 최소 거리 찾기
  for (int i = 1; i <= cnt; i++) {
    queue<pair<int, int>> q2;
    // dist 초기화
    for (int j = 0; j < N; j++) {
      fill(dist[j], dist[j] + N, -1);
    }

    // 섬 시작점 세팅
    for (int k = 0; k < N; k++) {
      for (int h = 0; h < N; h++) {
        if (board[k][h] == i) {
          dist[k][h] = 0;
          q2.push({k, h});
        }
      }
    }

    bool exit = false;
    while (!q2.empty()) {
      pair<int, int> cur = q2.front();
      q2.pop();

      for (int dir = 0; dir < sizeof(dx) / sizeof(int); dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];

        if (board[nx][ny] != 0 && board[nx][ny] != i) {
          min_dist = min(min_dist, dist[cur.X][cur.Y]);
          exit = true;
          break;
        }

        if (nx < 0 || nx >= N; ny < 0 || ny >= N)
          continue;
        if (dist[nx][ny] >= 0)
          continue;

        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        q2.push({nx, ny});
      }

      if (exit == true) {
        break;
      }
    }
  }

  cout << min_dist;

  return 0;
}