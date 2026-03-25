#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>

#define X first
#define Y second

using namespace std;

int board[105][105];
int N, M;
int dist[105][105];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < M; j++) {
      board[i][j] = s[j] - '0';
    }
  }

  for (int i = 0; i < N; i++) {
    fill(dist[i], dist[i] + M, -1);
  }

  queue<pair<int, int>> Q;

  dist[0][0] = 1;
  Q.push({0, 0});

  while (!Q.empty()) {
    pair<int, int> cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < sizeof(dx) / sizeof(int); dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if (nx < 0 || nx >= N || ny < 0 || ny >= M)
        continue;
      if (dist[nx][ny] != -1 || board[nx][ny] != 1)
        continue;

      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      Q.push({nx, ny});
    }
  }

  cout << dist[N - 1][M - 1];

  return 0;
}