#include <iostream>
#include <queue>
#include <string>
#include <utility>

#define X first
#define Y second

using namespace std;

string board[105];
int visit[105][105];
int visit_sick[105][105];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char col[3] = {'R', 'B', 'G'};
char col_sick[2] = {'R', 'B'};

int N;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> board[i];
  }

  queue<pair<int, int>> Q;

  int cnt_normal = 0;

  for (int k = 0; k < sizeof(col) / sizeof(char); k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (board[i][j] == col[k] && visit[i][j] == 0) {
          visit[i][j] = 1;
          Q.push({i, j});
          cnt_normal++;
        }

        while (!Q.empty()) {
          pair<int, int> cur = Q.front();
          Q.pop();

          for (int dir = 0; dir < sizeof(dx) / sizeof(int); dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
              continue;
            if (board[nx][ny] != col[k] || visit[nx][ny] != 0)
              continue;

            visit[nx][ny] = 1;
            Q.push({nx, ny});
          }
        }
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == 'G') {
        board[i][j] = 'R';
      }
    }
  }

  int cnt_sick = 0;
  for (int k = 0; k < sizeof(col_sick) / sizeof(char); k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (board[i][j] == col_sick[k] && visit_sick[i][j] == 0) {
          visit_sick[i][j] = 1;
          Q.push({i, j});
          cnt_sick++;
        }

        while (!Q.empty()) {
          pair<int, int> cur = Q.front();
          Q.pop();

          for (int dir = 0; dir < sizeof(dx) / sizeof(int); dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
              continue;
            if (board[nx][ny] != col[k] || visit_sick[nx][ny] != 0)
              continue;

            visit_sick[nx][ny] = 1;
            Q.push({nx, ny});
          }
        }
      }
    }
  }

  cout << cnt_normal << "\n";
  cout << cnt_sick << "\n";

  return 0;
}