#include <iostream>
#include <string>

using namespace std;

const int MX = 2000005;
int queue[MX];
int head = 0;
int tail = 0;

int size() { return tail - head; }

int empty() {
  if (size() <= 0) {
    return 1;
  }

  return 0;
}

void push(int x) { queue[tail++] = x; }

int pop() {
  if (empty()) {
    return -1;
  }
  return queue[head++];
}

int front() {
  if (empty()) {
    return -1;
  }
  return queue[head];
}

int back() {
  if (empty()) {
    return -1;
  }
  return queue[tail - 1];
}

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
      push(n);
    } else if (s.compare("front") == 0) {
      cout << front() << "\n";
    } else if (s.compare("back") == 0) {
      cout << back() << "\n";
    } else if (s.compare("size") == 0) {
      cout << size() << "\n";
    } else if (s.compare("empty") == 0) {
      cout << empty() << "\n";
    } else if (s.compare("pop") == 0) {
      cout << pop() << "\n";
    }
  }

  return 0;
}