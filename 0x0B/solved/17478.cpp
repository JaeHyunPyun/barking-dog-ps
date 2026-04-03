#include <iostream>
#include <string>

using namespace std;

int N;

void print_ans(int level) {
  int depth = N - level;
  int delimiter_size = depth * 4;
  string delimiter;

  for (int i = 0; i < delimiter_size; i++) {
    delimiter.append("_");
  }

  string body;
  string footer;

  if (level == 0) {
    body.append(delimiter)
        .append("\"재귀함수가 뭔가요?\"\n")
        .append(delimiter)
        .append("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n")
        .append(delimiter)
        .append("라고 답변하였지.\n");
    cout << body;
    return;
  }

  body.append(delimiter)
      .append("\"재귀함수가 뭔가요?\"\n")
      .append(delimiter)
      .append("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 "
              "지식을 통달한 선인이 있었어.\n")
      .append(delimiter)
      .append("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 "
              "지혜롭게 대답해 주었지.\n")
      .append(delimiter)
      .append("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 "
              "선인에게 한 선비가 찾아와서 물었어.\"\n");
  cout << body;
  print_ans(--level);

  footer.append(delimiter).append("라고 답변하였지.\n");
  cout << footer;
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << "\n";
  print_ans(N);

  return 0;
}