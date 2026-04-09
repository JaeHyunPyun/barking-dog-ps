#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define X first
#define Y second

int visit[302][302];
int L;

int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    cin >> L;
    int start_x;
    int start_y;
    int target_x;
    int target_y;
    cin >> start_x >> start_y >> target_x >> target_y;

    queue<pair<int, int>> q;

    for (int i = 0; i < L; i++) {
      fill(visit[i], visit[i] + L, -1);
    }

    visit[start_x][start_y] = 0;
    q.push({start_x, start_y});

    while (!q.empty()) {
      pair<int, int> cur = q.front();
      q.pop();

      if (cur.X == target_x && cur.Y == target_y) {
        cout << visit[cur.X][cur.Y] << "\n";
        break;
      }

      for (int dir = 0; dir < sizeof(dx) / sizeof(int); dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];

        if (nx < 0 || nx >= L || ny < 0 || ny >= L)
          continue;
        if (visit[nx][ny] >= 0)
          continue;

        visit[nx][ny] = visit[cur.X][cur.Y] + 1;
        q.push({nx, ny});
      }
    }
  }

  return 0;
}