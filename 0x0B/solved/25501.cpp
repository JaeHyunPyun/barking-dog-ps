#include <iostream>
#include <string>

using namespace std;

int recursion(string &s, int l, int r, int &cnt) {
  cnt++;

  if (r <= l)
    return 1;

  if (s[l] != s[r])
    return 0;
  else
    return recursion(s, l + 1, r - 1, cnt);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  while (N--) {
    string s;
    cin >> s;
    int cnt = 0;

    cout << recursion(s, 0, s.length() - 1, cnt) << " " << cnt << "\n";
  }

  return 0;
}