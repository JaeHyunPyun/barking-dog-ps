#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define X first
#define Y second

int board[50][50];
int visit[50][50];

int M, N, K;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;

  while (T--) {
    // 테스트 케이스별 배열 초기화
    for (int i = 0; i < 50; i++) {
      fill(board[i], board[i] + 50, 0);
      fill(visit[i], visit[i] + 50, 0);
    }

    cin >> M >> N >> K;

    // 배추 위치 표시
    while (K--) {
      int i;
      int j;
      cin >> i >> j;
      board[i][j] = 1;
    }

    int cnt = 0;
    queue<pair<int, int>> Q;
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        if (board[i][j] == 1 && visit[i][j] != 1) {
          visit[i][j] = 1;
          Q.push({i, j});
          cnt++;
        }

        while (!Q.empty()) {
          pair<int, int> cur = Q.front();
          Q.pop();

          for (int dir = 0; dir < sizeof(dx) / sizeof(int); dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N)
              continue;
            if (board[nx][ny] != 1 || visit[nx][ny] == 1)
              continue;

            visit[nx][ny] = 1;
            Q.push({nx, ny});
          }
        }
      }
    }
    cout << cnt << "\n";
  }

  return 0;
}