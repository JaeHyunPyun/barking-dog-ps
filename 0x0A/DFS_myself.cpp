#include <algorithm>
#include <iostream>
#include <stack>
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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n = 7;
int m = 10;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<pair<int, int>> s;

  vis[0][0] = 1;
  s.push({0, 0});

  while (!s.empty()) {
    pair<int, int> cur = s.top();
    s.pop();
    cout << "(" << cur.X << "," << cur.Y << ") -> ";

    for (int dir = 0; dir < sizeof(dx) / sizeof(int); dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (vis[nx][ny] == 1 || board[nx][ny] != 1)
        continue;

      vis[nx][ny] = 1;
      s.push({nx, ny});
    }
  }

  return 0;
}