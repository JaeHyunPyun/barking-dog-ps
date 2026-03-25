#include <iostream>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;

int board[502][502] = {
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0}, {1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
int vis[502][502];
int n = 7, m = 10;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // 초기 시작점 세팅
  queue<pair<int, int>> Q;
  vis[0][0] = 1;
  Q.push({0, 0});

  while (!Q.empty()) {
    // 실제 방문
    pair<int, int> cur = Q.front();
    Q.pop();
    cout << "(" << cur.X << "," << cur.Y << ") -> ";

    // 다음 방문 후보 삽입
    for (int dir = 0; dir < sizeof(dx) / sizeof(int); dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      // 후보 제외 조건1 : 보드 바깥
      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      // 후보 제외 조건2 : 이미 방문 or 파란색 아님
      if (vis[nx][ny] == 1 || board[nx][ny] != 1)
        continue;

      // 방문 후보 삽입
      vis[nx][ny] = 1;
      Q.push({nx, ny});
    }
  }

  return 0;
}