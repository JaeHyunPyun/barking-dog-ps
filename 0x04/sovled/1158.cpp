#include <iostream>

using namespace std;

const int MX = 5005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num) {
  // 신규 노드 생성
  dat[unused] = num;
  pre[unused] = addr;
  nxt[unused] = nxt[addr];

  // 다음 노드 pre 갱신
  if (nxt[addr] != -1) {
    pre[nxt[addr]] = unused;
  }

  // 이전 노드 nxt 갱신
  nxt[addr] = unused;

  // unused 증가
  unused++;
}

void erase(int addr) {
  // 이전 노드의 nxt 갱신
  nxt[pre[addr]] = nxt[addr];

  // 다음 노드의 pre 갱신
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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(pre, pre + MX, -1);
  fill(nxt, nxt + MX, -1);

  // N, K 입력
  int N, K;
  cin >> N >> K;

  // 원형 연결리스트 생성
  for (int i = 1; i <= N; i++) {
    insert(i - 1, i);
  }

  nxt[N] = 1;
  pre[1] = N;

  // K번째 사람 제거 루프
  int cur = 1;
  int count = 1;
  int arrayIndex = 0;
  int result[N] = {
      0,
  };

  while (true) {
    if (dat[cur] == nxt[cur]) {
      result[arrayIndex] = dat[cur];
      break;
    }

    if (count % K == 0) {
      result[arrayIndex] = dat[cur];
      arrayIndex++;
      erase(cur);
    }

    count++;
    cur = nxt[cur];
  }

  // 제거된 사람 순서대로 출력
  cout << "<";
  for (int i = 0; i < N; i++) {
    cout << result[i];
    if (i != N - 1) {
      cout << ", ";
    } else {
      cout << ">";
    }
  }

  return 0;
}