#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

// 삽입
void push(int x) { dat[tail++] = x; }

// 삭제
void pop() {
  if (tail <= head) {
    return;
  }
  head++;
}

// 맨 앞 요소 반환
int front() { return dat[head]; }

// 맨 뒤 요소 반환
int back() { return dat[tail - 1]; }

void test() {
  push(10);
  push(20);
  push(30);
  cout << front() << '\n'; // 10
  cout << back() << '\n';  // 30
  pop();
  pop();
  push(15);
  push(25);
  cout << front() << '\n'; // 30
  cout << back() << '\n';  // 25
}

int main(void) { test(); }
