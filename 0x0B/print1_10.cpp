#include <iostream>

using namespace std;

int N;

void print(int a) {
  if (a <= 0) {
    return;
  }
  cout << a << " ";
  print(--a);
}

int main() {
  cin >> N;
  print(N);
}