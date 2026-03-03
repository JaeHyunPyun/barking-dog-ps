#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int testCount = 0;
  cin >> testCount;

  for (int i = 0; i < testCount; i++) {
    list<char> L;
    list<char>::iterator cursor = L.end();
    string s;
    cin >> s;

    for (string::iterator it = s.begin(); it != s.end(); it++) {

      char currentCharacter = *it;

      if (currentCharacter == '<') {
        if (cursor != L.begin()) {
          cursor--;
        }
      } else if (currentCharacter == '>') {
        if (cursor != L.end()) {
          cursor++;
        }
      } else if (currentCharacter == '-') {
        if (cursor != L.begin()) {
          cursor--;
          cursor = L.erase(cursor);
        }
      } else {
        L.insert(cursor, currentCharacter);
      }
    }

    for (auto l : L) {
      cout << l;
    }
    cout << "\n";
  }

  return 0;
}