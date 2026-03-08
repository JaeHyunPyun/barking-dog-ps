#include <iostream>
#include <string>

using namespace std;

const int MX = 10005;
int dat[MX];
int head = 0, tail = 0;

void push(int x) { dat[tail++] = x; }

int pop() {
  // 큐에 들어있는 정수가 없는 경우
  if (head == tail) {
    return -1;
  }

  return dat[head++];
}

int size() { return tail - head; }

int empty() {
  if (size() == 0) {
    return 1;
  }

  return 0;
}

int front() {
  if (size() == 0) {
    return -1;
  }

  return dat[head];
}

int back() {
  if (size() == 0) {
    return -1;
  }

  return dat[tail - 1];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  while (n--) {
    string s;
    cin >> s;

    if (s.compare("push") == 0) {
      int x;
      cin >> x;
      push(x);
    } else if (s.compare("pop") == 0) {
      int removed = pop();
      cout << removed << "\n";
    } else if (s.compare("size") == 0) {
      cout << size() << "\n";
    } else if (s.compare("empty") == 0) {
      cout << empty() << "\n";
    } else if (s.compare("front") == 0) {
      cout << front() << "\n";
    } else if (s.compare("back") == 0) {
      cout << back() << "\n";
    }
  }

  return 0;
}