#include <iostream>
#include <queue>
#include <string>

using namespace std;

const int MX = 10005;
int dat[MX];
int head = 0, tail = 0;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  queue<int> q;

  int n;
  cin >> n;

  while (n--) {
    string s;
    cin >> s;

    if (s.compare("push") == 0) {
      int x;
      cin >> x;
      q.push(x);
    } else if (s.compare("pop") == 0) {
      if (!q.empty()) {
        int removed = q.front();
        q.pop();
        cout << removed << "\n";
      } else {
        cout << -1 << "\n";
      }
    } else if (s.compare("size") == 0) {
      cout << q.size() << "\n";
    } else if (s.compare("empty") == 0) {
      cout << q.empty() << "\n";
    } else if (s.compare("front") == 0) {
      if (!q.empty()) {
        cout << q.front() << "\n";
      } else {
        cout << -1 << "\n";
      }
    } else if (s.compare("back") == 0) {
      if (!q.empty()) {
        cout << q.back() << "\n";
      } else {
        cout << -1 << "\n";
      }
    }
  }

  return 0;
}