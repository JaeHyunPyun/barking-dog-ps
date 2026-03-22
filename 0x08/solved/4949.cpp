#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string &s, stack<char> &ST) {
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];

    if (c == '(' || c == '[') {
      ST.push(c);
    }

    if (c == ')' || c == ']') {
      if (ST.empty()) {
        return false;
      } else {
        char last = ST.top();
        if (c == ')' && last != '(') {
          return false;
        }
        if (c == ']' && last != '[') {
          return false;
        }
      }
      ST.pop();
    }
  }

  if (!ST.empty()) {
    return false;
  }

  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  while (getline(cin, s)) {
    if (s == ".") {
      continue;
    }

    stack<char> ST;
    bool b = isBalanced(s, ST);

    if (b == true) {
      cout << "yes" << "\n";
    } else {
      cout << "no" << "\n";
    }
  }

  return 0;
}