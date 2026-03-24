#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  int goodCount = 0;

  cin >> N;

  while (N--) {

    stack<char> ST;

    string s;
    cin >> s;

    bool goodChar = true;

    for (int i = 0; i < s.size(); i++) {
      char c = s[i];

      if (ST.empty()) {
        ST.push(c);
      } else {
        char top = ST.top();
        if (top == c) {
          ST.pop();
        } else {
          ST.push(c);
        }
      }
    }

    if (!ST.empty()) {
      goodChar = false;
    }

    if (goodChar == true) {
      goodCount++;
    }
  }

  cout << goodCount;

  return 0;
}