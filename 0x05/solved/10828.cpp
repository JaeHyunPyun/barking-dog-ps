#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<int> s;

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    string cmd;
    cin >> cmd;

    if (cmd.compare("push") == 0) {
      int numInput;
      cin >> numInput;
      s.push(numInput);
    } else if (cmd.compare("pop") == 0) {
      if (!s.empty()) {
        cout << s.top();
        s.pop();
      } else {
        cout << -1;
      }
      cout << "\n";
    } else if (cmd.compare("size") == 0) {
      cout << s.size() << "\n";
    } else if (cmd.compare("empty") == 0) {
      if (!s.empty()) {
        cout << 0;
      } else {
        cout << 1;
      }
      cout << "\n";
    } else if (cmd.compare("top") == 0) {
      if (!s.empty()) {
        cout << s.top();
      } else {
        cout << -1;
      }
      cout << "\n";
    }
  }

  return 0;
}
