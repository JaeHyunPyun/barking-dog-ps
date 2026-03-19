#include <iostream>
#include <string>

using namespace std;

const int MX = 10005;
int dat[2 * MX + 1];
int head = MX, tail = MX;

void push_front(int x) { dat[--head] = x; }

void push_back(int x) { dat[tail++] = x; }

int empty() {
  if (head == tail) {
    return 1;
  }

  return 0;
}

int size() { return tail - head; }

int front() {
  if (empty() == 1) {
    return -1;
  }

  return dat[head];
}

int back() {
  if (empty() == 1) {
    return -1;
  }

  return dat[tail - 1];
}

int pop_front() {
  int removed = front();

  if (removed != -1) {
    head++;
  }

  return removed;
}

int pop_back() {
  int removed = back();

  if (removed != -1) {
    tail--;
  }

  return removed;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  while (N--) {
    string s;
    cin >> s;
    if (s == "push_back") {
      int x;
      cin >> x;
      push_back(x);
    } else if (s == "push_front") {
      int x;
      cin >> x;
      push_front(x);
    } else if (s == "front") {
      cout << front() << "\n";
    } else if (s == "back") {
      cout << back() << "\n";
    } else if (s == "size") {
      cout << size() << "\n";
    } else if (s == "empty") {
      cout << empty() << "\n";
    } else if (s == "pop_front") {
      cout << pop_front() << "\n";
    } else if (s == "pop_back") {
      cout << pop_back() << "\n";
    }
  }

  return 0;
}