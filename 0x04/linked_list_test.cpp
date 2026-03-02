#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void print_node() {
  cout << " i   : " << " ";
  for (int i = 0; i <= unused; i++) {
    cout << i << " ";
  };
  cout << "\n";

  cout << " dat : " << " ";
  for (int i = 0; i <= unused; i++) {
    cout << dat[i] << " ";
  };

  cout << "\n";

  cout << " pre : " << " ";
  for (int i = 0; i <= unused; i++) {
    cout << pre[i] << " ";
  };

  cout << "\n";

  cout << " nxt : " << " ";
  for (int i = 0; i <= unused; i++) {
    cout << nxt[i] << " ";
  };

  cout << "\n";
}

void insert(int addr, int num) {
  // 신규 노드 추가
  dat[unused] = num;
  pre[unused] = addr;

  if (nxt[addr] == -1) {
    nxt[unused] = -1;
  } else {
    nxt[unused] = nxt[addr];
  }

  // 후행 노드 pre 수정
  if (nxt[addr] != -1) {
    pre[nxt[addr]] = unused;
  }

  // 선행 노드 nxt 수정
  nxt[addr] = unused;

  // unused 증가
  unused++;
}

void erase(int addr) {

  // 선행 노드의 nxt 수정
  nxt[pre[addr]] = nxt[addr];

  // 후행 노드의 pre 수정
  if (nxt[addr] != -1) {
    pre[nxt[addr]] = pre[addr];
  }
}

void traverse() {
  int cur = nxt[0];
  while (cur != -1) {
    cout << dat[cur] << ' ';
    cur = nxt[cur];
  }
  cout << "\n\n";
}

void insert_test() {
  cout << "****** insert_test *****\n";
  insert(0, 10); // 10(address=1)
  traverse();
  insert(0, 30); // 30(address=2) 10
  traverse();
  insert(2, 40); // 30 40(address=3) 10
  traverse();
  insert(1, 20); // 30 40 10 20(address=4)
  traverse();
  insert(4, 70); // 30 40 10 20 70(address=5)
  traverse();
  print_node();
}

void erase_test() {
  cout << "****** erase_test *****\n";
  erase(1); // 30 40 20 70
  traverse();
  erase(2); // 40 20 70
  traverse();
  erase(4); // 40 70
  traverse();
  erase(5); // 40
  traverse();
}

int main(void) {
  fill(pre, pre + MX, -1);
  fill(nxt, nxt + MX, -1);
  insert_test();
  erase_test();
}
