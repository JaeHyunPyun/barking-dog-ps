#include <iostream>
#include <queue>
#include <string>
#include <utility>

using namespace std;

#define X first
#define Y second

string board[1005];

int visit_fire[1005][1005];
int visit_s[1005][1005];

int w, h;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;

  while (T--) {
    cin >> w >> h;

    for (int i = 0; i < h; i++) {
      cin >> board[i];
    }

    queue<pair<int, int>> q_fire;
    queue<pair<int, int>> q_s;

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (board[i][j] == '*') {
          visit_fire[i][j] = 1;
          q_fire.push({i, j});
        }

        if (board[i][j] == '@') {
          visit_s[i][j] = 1;
          q_s.push({i, j});
        }
      }
    }

    while (!q_fire.empty()) {
      pair<int, int> cur = q_fire.front();
      q_fire.pop();

      for (int dir = 0; dir < sizeof(dx) / sizeof(int); dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];

        if (nx < 0 || nx >= h || ny < 0 || ny >= w)
          continue;
        if (board[nx][ny] == '#' || visit_fire[nx][ny] > 0)
          continue;

        visit_fire[nx][ny] = visit_fire[cur.X][cur.Y] + 1;
        q_fire.push({nx, ny});
      }
    }

    bool exit = false;
    while (!q_s.empty()) {
      pair<int, int> cur = q_s.front();
      q_s.pop();

      for (int dir = 0; dir < sizeof(dx) / sizeof(int); dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];

        int next_visit_value = visit_s[cur.X][cur.Y] + 1;

        if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
          exit = true;
          cout << visit_s[cur.X][cur.Y] << "\n";
          break;
        }
        if (board[nx][ny] == '#' || visit_s[nx][ny] > 0)
          continue;
        if (visit_fire[nx][ny] != 0 && next_visit_value >= visit_fire[nx][ny])
          continue;

        visit_s[nx][ny] = next_visit_value;
        q_s.push({nx, ny});
      }

      if (exit == true) {
        break;
      }
    }

    if (exit != true) {
      cout << "IMPOSSIBLE" << "\n";
    }

    for (int i = 0; i < 1005; i++) {
      fill(visit_fire[i], visit_fire[i] + 1005, 0);
      fill(visit_s[i], visit_s[i] + 1005, 0);
    }
  }

  return 0;
}