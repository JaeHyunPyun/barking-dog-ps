#include <iostream>
#include <string>

using namespace std;

const int MX = 10005;
int stackArray[MX];
int pos = 0;

void push(int num) { stackArray[pos++] = num; }

int pop() {
  if (pos == 0) {
    return -1;
  }
  return stackArray[--pos];
}

int size() { return pos; }

int empty() {
  if (pos == 0) {
    return 1;
  }

  return 0;
}

int top() {
  if (pos == 0) {
    return -1;
  }

  return stackArray[pos - 1];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    string cmd;
    cin >> cmd;

    if (cmd.compare("push") == 0) {
      int numInput;
      cin >> numInput;
      push(numInput);
    } else if (cmd.compare("pop") == 0) {
      cout << pop() << "\n";
    } else if (cmd.compare("size") == 0) {
      cout << size() << "\n";
    } else if (cmd.compare("empty") == 0) {
      cout << empty() << "\n";
    } else if (cmd.compare("top") == 0) {
      cout << top() << "\n";
    }
  }

  return 0;
}
