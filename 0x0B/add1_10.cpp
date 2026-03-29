#include <iostream>

using namespace std;

int N;

int sum(int a) {
  if (a == 10) {
    return 10;
  }

  return a + sum(a + 1);
}

int main() { cout << sum(1); }