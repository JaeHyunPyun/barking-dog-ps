#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  int orderCount;

  list<char> L;
  list<char>::iterator cursor = L.end();

  // String 입력
  cin >> s;
  for (string::iterator it = s.begin(); it != s.end(); it++) {
    L.push_back(*it);
  }

  // 명령 갯수 입력
  cin >> orderCount;

  // 명령 수행
  for (int i = 0; i < orderCount; i++) {
    char orderCharacter;
    char addedCharacter;

    cin >> orderCharacter;

    switch (orderCharacter) {
    case 'L':
      if (cursor != L.begin()) {
        cursor--;
      }
      break;

    case 'D':
      if (cursor != L.end()) {
        cursor++;
      }
      break;

    case 'B':
      if (cursor != L.begin()) {
        cursor--;
        cursor = L.erase(cursor);
      }
      break;

    case 'P':
      cin >> addedCharacter;
      L.insert(cursor, addedCharacter);
    }
  }

  for (list<char>::iterator it = L.begin(); it != L.end(); it++) {
    cout << *it;
  }

  return 0;
}