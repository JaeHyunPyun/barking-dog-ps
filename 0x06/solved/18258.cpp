#include <iostream>
#include <queue>
#include <string>

using namespace std;

queue<int> q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int orderCount;
  cin >> orderCount;

  while (orderCount--) {
    string s;
    cin >> s;

    if (s.compare("push") == 0) {
      int n;
      cin >> n;
      q.push(n);
    } else if (s.compare("front") == 0) {
      if (q.empty()) {
        cout << -1 << "\n";
      } else {
        cout << q.front() << "\n";
      }
    } else if (s.compare("back") == 0) {
      if (q.empty()) {
        cout << -1 << "\n";
      } else {
        cout << q.back() << "\n";
      }
    } else if (s.compare("size") == 0) {
      cout << q.size() << "\n";
    } else if (s.compare("empty") == 0) {
      cout << q.empty() << "\n";
    } else if (s.compare("pop") == 0) {
      if (q.empty()) {
        cout << -1 << "\n";
      } else {
        cout << q.front() << "\n";
        q.pop();
      }
    }
  }

  return 0;
}