#include <iostream>

using namespace std;

using ll = long long;

ll mod(ll a, ll b, ll c) {
  if (b == 1)
    return a % c;

  ll formal_residue = mod(a, b / 2, c);

  ll residue = formal_residue * formal_residue % c;
  if (b % 2 != 0) {
    residue = residue * a % c;
  }

  return residue;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll A, B, C;

  cin >> A >> B >> C;

  ll answer = mod(A, B, C);

  cout << answer;

  return 0;
}