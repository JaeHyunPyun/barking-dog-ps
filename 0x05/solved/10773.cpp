#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<int> s;

  int N;
  cin >> N;

  while (N--) {
    int input;
    cin >> input;

    if (input == 0) {
      if (!s.empty()) {
        s.pop();
      }
    } else {
      s.push(input);
    }
  }

  int sum = 0;
  while (!s.empty()) {
    sum += s.top();
    s.pop();
  }

  cout << sum;

  return 0;
}