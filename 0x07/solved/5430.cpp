#include <deque>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;

  while (T--) {
    deque<string> DQ;
    bool isReversed = false;
    bool hasError = false;

    string p;
    cin >> p;

    int N;
    cin >> N;

    string s;
    cin >> s;

    string target;

    for (int i = 0; i < s.size(); i++) { // O(N)
      char ithChar = s[i];
      if (ithChar != '[' && ithChar != ']' && ithChar != ',') {
        target.append(1, ithChar);
      }

      if (ithChar == ',' || ithChar == ']') {
        if (target.size() > 0) {
          DQ.push_back(target);
        }
        target.clear();
      }
    }

    for (int i = 0; i < p.size(); i++) { // O(P)
      if (p[i] == 'R') {                 // O(1)
        isReversed = !isReversed;
      } else if (p[i] == 'D') {
        if (DQ.empty()) {
          cout << "error";
          hasError = true;
          break;
        }

        if (isReversed) {
          DQ.pop_back();
        } else {
          DQ.pop_front();
        }
      }
    }

    if (!hasError) {
      cout << "[";

      if (isReversed) {
        for (int i = DQ.size() - 1; i >= 0; i--) {
          cout << DQ[i];
          if (i != 0) {
            cout << ",";
          }
        }
      } else {
        for (int i = 0; i < DQ.size(); i++) {
          cout << DQ[i];
          if (i != DQ.size() - 1) {
            cout << ",";
          }
        }
      }
      cout << "]";
    }
    cout << "\n";
  }

  return 0;
}